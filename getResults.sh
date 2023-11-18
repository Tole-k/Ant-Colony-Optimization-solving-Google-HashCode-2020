g++ solutionTester.cpp -o solutionTester

# for file in output/*; do
#     name="${file%%-*}".txt
#     name=$(echo $name | xargs -n 1 basename)
#     echo $file
# #    ./solutionTester "Round/"$name $file
# 	output=$(./$tester "Round/"$path $file)
#     $(echo $output | awk '{print $NF}')
# done

alfa=(1 2 4 8)
beta=(1 2 4)
gamma=(1 2 4)
p=(0.01 0.025 0.05)
max=0

for i in ${alfa[@]}; do
    for j in ${beta[@]}; do
        for k in ${gamma[@]}; do
            for l in ${p[@]}; do
                res=0
                for path in Round/f_*; do
                    filename=$(basename $path .txt)
                    output=$(./solutionTester $path output/$filename"-"$i"_"$j"_"$k"_"$l.out)
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