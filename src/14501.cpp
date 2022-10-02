#include<iostream>

using namespace std;
int* payment;
int* day;
int N;

int max_payment(int day_now, int pay_now) {
    if(day_now == N){
        return pay_now;
    }
    else if(day_now > N) {
        return -1;
    }
    int days = day[day_now];
    int pay = payment[day_now];
    //do this appointment
    int a = max_payment(day_now + days, pay_now + pay);
    //skip this appointment
    int b = max_payment(day_now + 1, pay_now);

    return max(a, b);
}


int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    payment = new int[N];
    day = new int[N];

    for(int i=0; i<N; i++) {
        cin >> day[i] >> payment[i];
    }

    cout << max_payment(0, 0) << "\n";



	return 0;
}






/*
dp

#include<iostream>

using namespace std;


int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int* payment;
    int* day;
    int N;
    int* d;
    cin >> N;
    payment = new int[N];
    day = new int[N];
    d = new int[N];

    for(int i=0; i<N; i++) {
        cin >> day[i] >> payment[i];
        if(day[i] + i > N) {
            payment[i] = 0;
        }
    }

    d[N-1] = payment[N-1]; //initialize d[last day] 
    for(int i=N-2; i>=0; i--) { //from (last day-1),
        if(day[i] + i > N-1) {
            d[i] = max(d[i+1], payment[i]);
        }
        else {
            d[i] = max(d[i+1], payment[i] + d[i+day[i]]);
        }
    }

    cout << d[0] << "\n";



	return 0;
}
*/
