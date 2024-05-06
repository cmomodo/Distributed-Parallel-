!/bin/bash

if [ "$1" == "" ]; then
    echo "Positional parameter 1 is empty"
else

mpirun -np 10 -hostfile /etc/pdsh/machines --map-by node $1

fi
