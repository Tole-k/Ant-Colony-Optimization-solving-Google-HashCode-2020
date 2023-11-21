#!/bin/bash - 

name="main"
tester="tools/solutionTester"


g++ $tester.cpp -o $tester.exe
res=0
totalRuntime=0.0

for path in test/*; do
	echo $path

	start=`date +%s.%N`

	filename=$(basename $path .txt)
	./cmake-build-debug/$name < $path > output/$filename.out

	end=`date +%s.%N`
	runtime=$( echo "$end - $start" | bc -l )

	output=$(./$tester $path output/$filename.out)
	((res=res+$(echo $output | awk '{print $NF}')))

	echo "runtime:" $runtime
	echo "$output"
	echo
done
 
printf "final score: %'d\n" $res

