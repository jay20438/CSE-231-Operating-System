#! /bin/bash
echo "Enter the operation to be performed along with numbers."
echo "1. add"
echo "2. sub(subtract)"
echo "3. mul(multiply)"
echo "4. div(divide)"
echo "5. exp(exponent)"

arr=( "$@" )

prod=1
ans=1
pow=1
function add()
{
   for i in ${arr[@]:1}
   do
      val=$(($val+$i))
      echo "$1"
      
   done
   echo "The value is $val"
}

function sub()
{
   val=$(($val-${arr[1]}))
   val=$(($val*(-1)))
   for i in ${arr[@]:2}
   do
      val=$(($val-$i))
      
   done
   echo "The value is $val"
}

function mul()
{
   for i in ${arr[@]:1}
   do
      prod=$((prod*i))
   done
   echo "The value is $prod"
}

function div()
{
   for i in ${arr[@]:1}
   do
      ans=$((i/ans))
   done
   echo "The value is $ans"
}

function exp()
{
   for i in ${arr[@]:1}
   do
      pow=$((i**pow))
   done
   echo "The value is $pow"
}

if [ "$1" == "add" ]
then
      add
elif [ "$1" == "sub" ]
then 
      sub
elif [ "$1" == "mul" ]
then
     mul
elif [ "$1" == "div" ]
then
     div
elif [ "$1" == "exp" ]
then
     exp
fi
