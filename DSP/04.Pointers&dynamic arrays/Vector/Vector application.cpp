#include<iostream>
#include<cmath>
#include<map>
#include<random>
#include<vector>
using namespace std;

double Sigmoid(double x) {
	return 1 / (1 + exp(-x));
}

class Neuron {
public:
	Neuron(size_t input_size) {
		Weights_.resize(input_size);
		Reset();
	}
public:
	double Compute(const vector<double>& x) const {
		if (x.size() != Weights_.size()) {
			throw "x.size() != Weights_.size()";
		}

		double wx = 0.0;
		for (size_t i = 0; i < Weights_.size(); +i) {
			wx += Weights_[i] * x[i];
		}
		return Sigmoid(wx + Bias_);
	}
	void Train(double a, const vector<pair<vector<double>, double>>& train_data) {
		size_t input_size = train_data[0].first.size();
		if (input_size != Weights_.size()) {
			throw "input_size != Weights_.size()";
		}
		for (size_t i = 0; i < train_data.size(); ++i) {
			double o = Compute(train_data[i].first);
			double t = train_data[i].second;

			for (size_t j = 0; j < input_size; ++j) {
				Weights_[j] += a*(t - o)* train_data[i].first[j];
			}
			Bias_ += a * (t - o);
		}
	}
private:
	void Reset() {
		Bias_ = -1;

		mt19937 random((random_device()()));
		uniform_real_distribution<double> dist(-1, 1);

		for (size_t i = 0; i < Weights_.size(); ++i) {
			Weights_[i] = dist(random);
		}
	}
private:
	vector<double> Weights_;
	double Bias_;
};

int main() {
	Neuron and_neuron(2);

	for (int i = 0; i < 100000; ++i) {
		and_neuron.Train(0.1,
			{
				{{0,0},0},
				{{1,0},0},
				{{0,1},0},
				{{1,1},1},
			});
	}

	cout << "AND 연산 학습" << endl;
	cout << "0 and 0 = " << and_neuron.Compute({ 0,0 }) << '\n';
	cout << "1 and 0 = " << and_neuron.Compute({ 1,0 }) << '\n';
	cout << "0 and 1 = " << and_neuron.Compute({ 0,1 }) << '\n';
	cout << "1 and 1 = " << and_neuron.Compute({ 1,1 }) << '\n';

	Neuron or_neuron(2);

	for (int i = 0; i < 100000; ++i) {
		or_neuron.Train(0.1,
			{
				{{0,0},0},
				{{1,0},1},
				{{0,1},1},
				{{1,1},1},
			});
	}

	cout << "OR 연산 학습" << endl;
	cout << "0 or 0 = " << or_neuron.Compute({ 0,0 }) << '\n';
	cout << "1 or 0 = " << or_neuron.Compute({ 1,0 }) << '\n';
	cout << "0 or 1 = " << or_neuron.Compute({ 0,1 }) << '\n';
	cout << "1 or 1 = " << or_neuron.Compute({ 1,1 }) << '\n';

	return 0;
}