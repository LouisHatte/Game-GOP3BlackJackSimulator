echo "$1"

if [ "$#" -ne 1 ]; then
    echo "Please, give one file_name as argument"
    exit 1
fi

cd .. ; make re && clear ; ./bin/bj $1 && python3 python/graph.py output/$1
