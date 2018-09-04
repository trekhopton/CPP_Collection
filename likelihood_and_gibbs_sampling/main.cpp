#include <iostream>
#include <vector>
#include <fstream>
#include <utility>
#include <unordered_map>
using namespace std;

// ------------ LIKELIHOOD METHOD -------------

pair<float, float> likelihood(vector<bool> evidence, int n){
	int totalTimeSteps = evidence.size();

	//eg. <sample = {001}, <weight = 0.8, count = 20> >
	unordered_map<vector<bool>,pair<float, int> > samples;

	int N = n;
	for(int i = 0; i < N; i++){
		//sample only contains values for unobserved vars since evidence is fixed
		vector<bool> sample;
		float weight = 1;
		// P( R0 = True ) = 0.2
		if(rand() % 100 < 20){
			sample.push_back(1);
		} else {
			sample.push_back(0);
		}
		if(sample[0]){
			if(evidence[0]){
				weight = weight * 0.9;
			} else {
				weight = weight * 0.1;
			}
		} else {
			if(evidence[0]){
				weight = weight * 0.2;
			} else {
				weight = weight * 0.8;
			}
		}
		for(int t = 1; t < totalTimeSteps; t++){
			if(sample[t-1]){
				// P ( Rt = True | Rt-1 = True ) = 0.7
				if(rand() % 100 < 70){
					sample.push_back(1);
				} else {
					sample.push_back(0);
				}
			} else {
				// P ( Rt = True | Rt-1 = False ) = 0.3
				if(rand() % 100 < 30){
					sample.push_back(1);
				} else {
					sample.push_back(0);
				}
			}
			if(sample[t]){
				if(evidence[t]){
					weight = weight * 0.9;
				} else {
					weight = weight * 0.1;
				}
			} else {
				if(evidence[t]){
					weight = weight * 0.2;
				} else {
					weight = weight * 0.8;
				}
			}
		}
		if(samples.find(sample) == samples.end()){
			pair<float, int> sampleData(weight, 1);
			samples[sample] = sampleData;
		} else {
			samples[sample].second++;
		}
	}

	// Calculating P(RT | evidence)

	float resultTrue = 0;
	float resultFalse = 0;
	for(unordered_map<vector<bool>, pair<float,int> >::iterator iter = 
	samples.begin(); iter != samples.end(); ++iter){
		if(iter->first[totalTimeSteps-1]){
			resultTrue += (iter->second.first * iter->second.second);
		} else {
			resultFalse += (iter->second.first * iter->second.second);
		}
	}
	//normalising prob.s
	float normT = resultTrue/(resultTrue+resultFalse);
	float normF = resultFalse/(resultTrue+resultFalse);

	return pair<float, float>(normT, normF);
}

//------------------- GIBBS METHOD ----------------------

pair<float, float> gibbs(vector<bool> evidence, int n){

	int totalTimeSteps = evidence.size();

	int N = n;
	//event to be changed each iteration
	vector<bool> states;
	//random initialisation of state space
	for(int i = 0; i < totalTimeSteps; i++){
		if(rand() % 2 == 1){
			states.push_back(1);
		} else {
			states.push_back(0);
		}
	}
	//number of RT = T samples and RT = False samples
	float Tcount = 0;
	float Fcount = 0;
	for(int i = 0; i < N; i++){
		for(int t = 0; t < totalTimeSteps; t++){
			//construct prob distribution for Rt given Markov Blanket
			//Term 1 (don't calculate at start)
			float T1 = 1;
			float F1 = 1;
			if(t != 0){
				if(states[t-1]){
					T1 = 0.7;
				} else {
					T1 = 0.3;
				}
				if(states[t-1]){
					F1 = 0.3;
				} else {
					F1 = 0.7;
				}
			}
			//Term 2
			float T2 = 1;
			float F2 = 1;
			if(evidence[t]){
				T2 = 0.9;
			} else {
				T2 = 0.1;
			}
			if(evidence[t]){
				F2 = 0.2;
			} else {
				F2 = 0.8;
			}
			//Term 3 (don't calculate at end)
			float T3 = 1;
			float F3 = 1;
			if(t != totalTimeSteps - 1){
				if(states[t+1]){
					T3 = 0.7;
				} else {
					T3 = 0.3;
				}
				if(states[t+1]){
					F3 = 0.3;
				} else {
					F3 = 0.7;
				}
			}

			float PtT = T1 * T2 * T3;
			float PtF = F1 * F2 * F3;
			// P(Rt = T | Markov Blanket of Rt)
			float normT = PtT/(PtT+PtF);
			// P(Rt = F | Markov Blanket of Rt)
			float normF = PtF/(PtT+PtF);

			//randomly update Ri based on prob. distribution
			float r = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
			if(r < normT){
				states[t] = 1;
			} else {
				states[t] = 0;
			}

			//check if in this sample RT = T
			if(states[totalTimeSteps-1]){
				Tcount++;
			} else {
				Fcount++;
			}
		}
	}

	// Calculating P(RT | evidence) normalised

	float normT = Tcount/(Tcount+Fcount);
	float normF = Fcount/(Tcount+Fcount);

    return pair<float, float>(normT, normF);
}

int main(int argc, char** argv){

	// check for right number of args
    if(argc != 2){
        cerr << "ERROR: " << argc << " arguments recieved, expected 2" << endl;
		return 1;
    }
	// parse input from given file
	string fileName(argv[1]);
	bool u;
	vector<bool> evidence;
	ifstream infile(fileName);
	while (infile >> u){
		evidence.push_back(u);
	}
	infile.close();

	// for(int i = 100; i <= 20000; i++){
		pair<float, float> lik = likelihood(evidence, 1000);
		pair<float, float> gib = gibbs(evidence, 1000);

		cout << lik.first << " " << lik.second << " Likelihood" << endl;
		cout << gib.first << " " << gib.second << " " << "Gibbs" << endl;
	//}


	return 0;
}


