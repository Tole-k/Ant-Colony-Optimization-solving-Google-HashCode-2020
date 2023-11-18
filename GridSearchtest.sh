#!/bin/bash - 

name="main"
tester="solutionTester"


# g++ $name.cpp -O3 --static -o $name
g++ $name.cpp Ant.cpp Library.cpp AntColonyOptimization.cpp Book.h GreedyAnt.cpp PheromoneAnt.cpp -g -o $name -O3 --static
g++ $tester.cpp -o $tester
res=0
totalRuntime=0.0
alfa=(1 2 4 8)
beta=(1 2 4)
gamma=(1 2 4)
p=(0.01 0.025 0.05)

for path in Round/*; do
	echo $path
	for i in ${alfa[@]}; do
		for j in ${beta[@]}; do
			for k in ${gamma[@]}; do
				for l in ${p[@]}; do
#					start=`date +%s.%N`

					filename=$(basename $path .txt)
					./$name $i $j $k $l < $path > output/$filename"-"$i"_"$k"_"$k"_"$l.out &
				#	./$name < $path 

					# end=`date +%s.%N`
					# runtime=$( echo "$end - $start" | bc -l )
				#	((totalRuntime=totalRuntime+runtime))

					# output=$(./$tester $path output/$filename.out)
					# ((res=res+$(echo $output | awk '{print $NF}')))

					# echo "runtime:" $runtime
					# echo "$output"
				done
			done
		done
	done
done
 
# printf "final score: %'d\n" $res
#echo $totalRuntime
