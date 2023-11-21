g++ solutionTester.cpp -o solutionTester

alfa=(4 8)
beta=(2 4)
gamma=(2 4)
p=(0.05 0.1 0.2)
max=0

for i in ${alfa[@]}; do
    for j in ${beta[@]}; do
        for k in ${gamma[@]}; do
            for l in ${p[@]}; do
                res=0
                for path in test/[bef]*; do
                    filename=$(basename $path .txt)
                    output=$(./solutionTester $path output/$filename"_"$i"_"$j"_"$k"_"$l.out)
                    ((res=res+$(echo $output | awk '{print $NF}')))
                                            
                done
                echo $i $j $k $l
                echo $res
                if [[ res -ge max ]]; then
                    max=$res
                    maxParams=$i"_"$j"_"$k"_"$l
                fi
            done
        done
    done
done

echo "max: " $max $maxParams
