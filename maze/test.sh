#!/bin/bash
all_counter=0
pass_counter=0


echo -e "~~ Argument Tests ~~"


# test 2 arguments without filname
((all_counter++))
echo -n "Testing 2 arguments - "
timeout 0.2s ./maze x x > tmp
if grep -q "Argument error" tmp;
then
    echo -e "\e[32mPASS\e[0m"
    ((pass_counter++))
else
    echo -e "\e[31mFAIL\e[0m"
fi



echo -e "\n~~ File Handling~~"

# input incorrect filename
((all_counter++))
echo -n "Testing bad filename - "
timeout 0.2s ./maze bad.txt > tmp
if grep -q "Error: cannot find file" tmp;
then
    echo -e "\e[32mPASS\e[0m"
    ((pass_counter++))
else
    echo -e "\e[31mFAIL\e[0m"
fi

# check the file content correct
((all_counter++))
echo -n "too many Start point - "
timeout 0.2s ./maze ./testData/badData1.txt > tmp
if grep -q "Error: file does not have expected format" tmp;
then
    echo -e "\e[32mPASS\e[0m"
    ((pass_counter++))
else
    echo -e "\e[31mFAIL\e[0m"
fi

# check empty data in the file
((all_counter++))
echo -n "empty data - "
timeout 0.2s ./maze ./testData/emptyData.txt > tmp
if grep -q "Error: file does not have expected format" tmp;
then
    echo -e "\e[32mPASS\e[0m"
    ((pass_counter++))
else
    echo -e "\e[31mFAIL\e[0m"
fi


# load file into maze correctly 
((all_counter++))
echo -n "Testing file loads successfully - "
timeout 0.2s ./maze ./testData/rightSize.txt > tmp
if grep -q "File successfully loaded." tmp;
then
    echo -e "\e[32mPASS\e[0m"
    ((pass_counter++))
else
    echo -e "\e[31mFAIL\e[0m"
fi

echo -e "\n~~ input ~~"

# input undefined char
((all_counter++))
echo -n "Testing wrong input - "
timeout 0.2s ./maze ./testData/rightSize.txt < ./testInput/wrongInput.txt > temp
if grep -q "Wrong input" temp;
then
    echo -e "\e[32mPASS\e[0m"
    ((pass_counter++))
else
    echo -e "\e[31mFAIL\e[0m"
fi


echo -e "\n~~ test basic function ~~"

# cannot move through walls
((all_counter++))
echo -n "Testing wrong way - "
timeout 0.2s ./maze ./testData/rightSize.txt < ./testInput/wrongWay.txt > temp
if grep -q "can not pass" temp;
then
    echo -e "\e[32mPASS\e[0m"
    ((pass_counter++))
else
    echo -e "\e[31mFAIL\e[0m"
fi

# test if it moves correctly
((all_counter++))
echo -n "Testing right way - "
timeout 0.2s ./maze ./testData/rightSize.txt < ./testInput/rightWay.txt > temp
if grep -q "win" temp;
then
    echo -e "\e[32mPASS\e[0m"
    ((pass_counter++))
else
    echo -e "\e[31mFAIL\e[0m"
fi

#test whether the map is shown correctly
((all_counter++))
echo -n "Testing show map - "
timeout 0.2s ./maze ./testData/rightSize.txt < ./testInput/showMap.txt > temp
if grep -q "#   X    #             #" temp && grep -q "#   S    #             #";
then
    echo -e "\e[32mPASS\e[0m"
    ((pass_counter++))
else
    echo -e "\e[31mFAIL\e[0m"
fi

# test the player reach the exit point
((all_counter++))
echo -n "Testing win - "
timeout 0.2s ./maze ./testData/rightSize.txt < ./testInput/win.txt > temp
if grep -q "win" temp;
then
    echo -e "\e[32mPASS\e[0m"
    ((pass_counter++))
else
    echo -e "\e[31mFAIL\e[0m"
fi





echo "Total tests: $all_counter"
echo "Passed tests: $pass_counter"
echo "Percentage passed: $(echo "scale=2; $pass_counter*100 / $all_counter" | bc)%"
rm -f tmp