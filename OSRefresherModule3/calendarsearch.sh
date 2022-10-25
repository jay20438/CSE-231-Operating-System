#! /bin/bash

if [ $3%4 == 0 ] && [ $3%100 != 0 ] || [ $3%400 == 0 ] 
#Checking the condition to see whether the entered year is a leap year.
then
#Special condition to check February on the basis of leap year.
     if [[ $1 -le 29 ]] && [ $2 == 02 ]
     then
               cal $1 $2 $3     
     elif [[ $1 -le 28 ]] && [ $2 == 02 ]
       then 
            cal 
     fi
fi


if [ $2 == 01 ] || [ $2 == 03 ] || [ $2 == 05 ] || [ $2 == 07 ] || [ $2 == 08 ] || [ $2 == 10 ] || [ $2 == 12 ]
#condition to check months with 31 days.
then
    if [[ $1 -le 31 ]]
    then
         cal $2 $3
    fi
elif [ $2 == 04 ] || [ $2 == 06 ] || [ $2 == 09 ] || [ $2 == 11 ]
#condition to check months with 30  days.
then
    if [[ $1 -le 30 ]]
       then
           cal $2 $3
    fi
else
     echo "Date not valid!"
fi
           
          
