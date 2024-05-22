#include <iostream>
#include <vector>
using namespace std;

class Processor{
public:
    virtual void Process(double* data, unsigned int size) = 0;
};

class Printer : public Processor{
public:
    virtual void Process(double* data, unsigned int size);
};
void Printer::Process(double* data, unsigned int size){
    for (int i = 0; i < size; ++i) {
        cout << data[i] << endl;
    }
}

class Adder : public Processor{
private:
    double sum;
public:
    Adder() {
        sum  = 0.0;
    }

    virtual void Process(double* data, unsigned int size) {
        for (int i = 0; i < size; ++i) {
            sum += data[i];
        }
    }

    double GetSum()const {
        return sum;
    }
};

void Kimani(vector<int> data, Processor& p){
    double* reals = new double[data.size()];
    for (int i=0; i<data.size(); i++) {
        reals[i] = data[i];
    }
    p.Process(reals, data.size());
    delete[] reals;
}

void Paulson(double array[], unsigned int s, Processor& p){
    p.Process(array, s);
}


int main() {
    double numbers[5] = {1, 2, 3, 4, 5};
    Adder a;
    Printer b;
    Paulson(numbers, 5, a);
    cout << a.GetSum() << endl;
    Paulson(numbers, 5, b);
    return 0;
}
