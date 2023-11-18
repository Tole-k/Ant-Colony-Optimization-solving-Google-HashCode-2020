#!/bin/bash - 

name="main"
tester="solutionTester"


# g++ $name.cpp -O3 --static -o $name
g++ $name.cpp Ant.cpp Library.cpp AntColonyOptimization.cpp Book.h GreedyAnt.cpp PheromoneAnt.cpp -o $name -O3 --static
g++ $tester.cpp -o $tester
res=0
totalRuntime=0.0

for path in Round/*; do
	echo $path

	start=`date +%s.%N`

	filename=$(basename $path .txt)
	./$name 8 1 1 0.05 < $path > output/$filename.out
#	./$name < $path 

	end=`date +%s.%N`
	runtime=$( echo "$end - $start" | bc -l )
#	((totalRuntime=totalRuntime+runtime))

	output=$(./$tester $path output/$filename.out)
	((res=res+$(echo $output | awk '{print $NF}')))

	echo "runtime:" $runtime
	echo "$output"
	echo
done
 
printf "final score: %'d\n" $res
#echo $totalRuntime

