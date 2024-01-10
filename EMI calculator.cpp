#include<iostream>
#include <math.h>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
//home loan calculator

class calculator
{
    public:
        void cal_emi(float amount,float int_r,float period)
        {
            // EMI = [P x R x (1+R)^N]/[(1+R)^N-1]
            // P=amount
            // R=interest int_rate
            // N=loan period in months
            float emi;
            float A,B,C,D,int_rate,N;
            int_rate = int_r / (12 * 100);
            //for calculating period in months we have to multiply years by 12
            N=period*12;
            A=1+int_rate;
            B=pow(A,N);
            C=B-1;
            D = (amount * int_rate * B);
            emi=D/C;
            cout<<"Emi(monthly):"<<emi;
        }


        

        void cal_rate(float amount,float period,float EMI)
         {
            //Rate= (EMI/loan amount)/(Number of EMIs per year )×12×100

            float SI,totalPayment,totalInterest;//simple interest
            float rate;
            // SI=(period*12)*EMI;
            // rate=(SI*100)/(amount*period);
            //double totalPayment = EMI * 12 * period;

            // Calculate interest paid over the loan tenure
             //totalInterest = totalPayment - amount;

            // Calculate annual interest rate
           // rate = (totalInterest /amount) / period * 100;
            // SI=(EMI/amount)/(12);
            // rate=SI*12*100;


            // Convert annual rate to monthly and then to a decimal
            float monthlyRate = (EMI / amount) * 12 / 100;

            // Calculate total number of payments
             totalPayment = period * 12;

            // Calculate annual interest rate using the formula
            float annualRate = (monthlyRate * pow((1 + monthlyRate), totalPayment)) / (pow((1 + monthlyRate), totalPayment) - 1);
            cout<<"INTEREST RATE:"<<annualRate;
         }

         void cal_tenure(float amount,float EMI,float int_r)
         {
            // Convert annual rate to monthly rate
            double monthlyRate = int_r / 100 / 12;

            // Calculate the number of payments needed to pay off the loan
            int numberOfPayments = ceil(-log(1 - (amount * monthlyRate) / EMI) / log(1 + monthlyRate));

            // Convert months to years
            int years = numberOfPayments / 12;

            cout << "The loan tenure is: " << years << " years." << endl;
         }

         void cal_amount(float period,float int_r,float EMI)
         {
            
            // Convert annual rate to monthly rate
            double monthlyRate = int_r / 100 / 12;
            
            // Convert years to months
            int numberOfPayments = period * 12;

            // Calculate loan amount using the formula for a fixed-rate loan
            double loanAmount = (EMI * (1 - pow(1 + monthlyRate, -numberOfPayments))) / monthlyRate;

            cout << "The loan amount is: " << loanAmount << endl;

    
         }

         
};

int main()
{
    float amount;       //rupees
    float int_r;       //percentage
    float period;     //years
    float EMI ;      //monthly
    int ch;
    calculator obj;
    do{
        cout<<"----------------------------------------------------------------------------"<<endl;
        cout<<"________________________WELCOME TO LOAN CALCULATOR__________________________"<<endl;
        cout<<"----------------------------------------------------------------------------"<<endl;
        cout<<"select what you want to calculate"<<endl;
        cout<<"1.AMOUNT"<<endl;
        cout<<"2.INTEREST RATE"<<endl;
        cout<<"3.PERIOD"<<endl;
        cout<<"4.EMI"<<endl;

        cout<<"Enter No:";
        cin>>ch;

        switch (ch)
        {
        case 1:
            cout<<"Enter the loan period in years:";
            cin>>period;
            cout<<"Enter  Interest rate in (percentage) %:";
            cin>>int_r;
            cout<<"Enter EMI monthly:";
            cin>>EMI;

            obj.cal_amount(period,int_r,EMI);

            break;
        case 2:
            cout<<"Enter the loan amount:";
            cin>>amount;
            cout<<"Enter loan period in years:";
            cin>>period;
            cout<<"Enter EMI monthly:";
            cin>>EMI;
   
            obj.cal_rate(amount,period,EMI);
            break;
        case 3:
            cout<<"Enter the loan amount:";
            cin>>amount;
            cout<<"Enter Interest rate in (percentage) %:";
            cin>>int_r;
            cout<<"Enter EMI monthly:";
            cin>>EMI;
   
            obj.cal_tenure(amount,EMI,int_r);
            
            break;
        case 4:
            cout<<"Enter the loan amount:";
            cin>>amount;
            cout<<"Enter Interest rate in (percentage) %:";
            cin>>int_r;
            cout<<"Enter loan period in Years:";
            cin>>period;
   
            obj.cal_emi(amount,int_r,period);
            break;
        default:
            cout<<"INVALID INPUT";
            break;
        }

    }while(ch!=5);
}