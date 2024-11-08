#include<iostream>
#include<queue>
#include<cassert>
#include<cstdlib>
using namespace std;

class washer{
public:
    washer(unsigned int s){
        seconds_for_wash=s;
        wash_time_left=0;
    }

    void one_second(){
        if(is_busy())--wash_time_left;
    }

    void start_washing(){
        assert(!is_busy());
        wash_time_left=seconds_for_wash;
    }

    bool is_busy() const{
        return(wash_time_left>0);
    }
private:
    unsigned int seconds_for_wash;
    unsigned int wash_time_left;
};

class bool_source{
public:
    bool_source(double p){
        assert(p>=0);
        assert(p<=1);
        probability=p;
    }

    bool query() const{
        return(rand()<probability * RAND_MAX);
    }
private:
    double probability;
};

class averager{
public:
    averager(){
        count=0;
        sum=0;
    }

    void next_number(double value){
        ++count;
        sum+=value;
    }

    size_t how_many_numbers() const{return count;}
    double average() const{
        assert(how_many_numbers()>0);
        return sum/count;
    }
private:
    size_t count;
    double sum;
};

void car_wash_simulate(unsigned int wash_time, double arrival_prob,unsigned int total_time){
    queue<unsigned int> arrival_times;
    bool_source arrival(arrival_prob);
    washer machine(wash_time);
    averager wait_times;

    for(unsigned int current_second = 0; current_second<total_time; ++current_second){
        if(arrival.query()){
            arrival_times.push(current_second);
        }
        if(!machine.is_busy() && !arrival_times.empty()){
            unsigned int next = arrival_times.front();
            arrival_times.pop();
            wait_times.next_number(current_second-next);
            machine.start_washing();
        }
        machine.one_second();
    }
    cout<<"Total cars washed: "<<wait_times.how_many_numbers()<<endl;
    if(wait_times.how_many_numbers()>0){
        cout<<"Average wait time: "<<wait_times.average()<<" seconds."<<endl;
    }
}
int main(){
    const unsigned int WASH_TIME = 60;
    const double ARRIVAL_PROB = 0.1;
    const unsigned int SIMULATION_TIME = 3600;

    car_wash_simulate(WASH_TIME, ARRIVAL_PROB, SIMULATION_TIME);

    return 0;
}