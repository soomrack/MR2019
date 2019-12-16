#include <stdio.h>

int main() {
   double KreditProz = 125.0;
   double DepozitProz = 108.0;
   long int BunkAkk = 20000000;
   long int Sum =1000000;
   long int Kreditors = 0;
   long int Depositors = 0;
   long int MaxMounthKreditors = 25;
   long int Time = 12*5;
   long int Depozitors[Time];

   int b = 0;

   for (int n = 0; (int)(KreditProz*b/12) <= 100;n++ )
   {
       b = b + 1;
   }
   double p = KreditProz*(double)b/12.0 - DepozitProz;
   if (p <= 0)
   {
       b++;
   }
   for (int t = 0; t <= Time;t++  )
   {
       if (t <= Time - b)
       {
           Kreditors = Kreditors + MaxMounthKreditors;
           MDepozitors[t] = (long int)((MaxMounthKreditors*Sum - BunkAkk)/Sum);
           if (MDepozitors[t] < 0)
           {
               MDepozitors[t] = 0;
           }
           Depositors = Depositors + MDepozitors[t];
           if (t < 12)
           {
               BunkAkk = BunkAkk - MaxMounthKreditors*Sum + MDepozitors[t]*Sum + (long int)((Kreditors*Sum*KreditProz/12.0)/100);

           }
           else
           {
               Kreditors = Kreditors - MaxMounthKreditors;
               BunkAkk = BunkAkk - MaxMounthKreditors*Sum + MDepozitors[t]*Sum + (long int)((Kreditors*Sum*KreditProz/12.0)/100) - (long int)((MDepozitors[t-12]*Sum*DepozitProz)/100);
               Depositors = Depositors - MDepozitors[t-12];
       }
       }
       if ((Time - b < t) && (t < Time))
       {
           MDepozitors[t] = 0;
           if (t < 12)
           {
               BunkAkk = BunkAkk + (long int)((Kreditors*Sum*KreditProz/12.0)/100);
           }
           else
           {
               Kreditors = Kreditors - MaxMounthKreditors;
               BunkAkk = BunkAkk + (long int)((Kreditors*Sum*KreditProz/12.0)/100) - (long int)((MDepozitors[t-12]*Sum*DepozitProz)/100);
               Depositors = Depositors - MDepozitors[t-12];
           }
       }
       if (t == Time )
       {
           MDepozitors[t] = 0;
           if (t < 12)
           {
               BunkAkk = BunkAkk + (long int)((Kreditors*Sum*KreditProz/12.0)/100) - (long int)((Depositors*Sum*DepozitProz)/100);
               Depositors = 0;
           }
           else
           {
               Kreditors = Kreditors - MaxMounthKreditors;
               BunkAkk = BunkAkk + (long int)((Kreditors*Sum*KreditProz/12.0)/100) - (long int)((Depositors*Sum*DepozitProz)/100);
               Depositors = 0;
           }
       }

       printf("Mounth = %d, Kreditors = %ld, Depositers = %ld, BankAkk = %ld, Depositor[i] = %ld\n", t, Kreditors, Depositors, BunkAkk, MDepozitors[t] );

   }
    printf("%d",b);


    return 0;
}