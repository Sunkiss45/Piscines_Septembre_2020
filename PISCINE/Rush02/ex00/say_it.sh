#!/bin/sh

echo 'Quel nombre souhaitez vous entendre ?'
read NB
if [ -e rush-02 ]
then
	./rush-02 ${NB}
	say -v Alex ${NB}
else
	(make && make clean) > /dev/null
	./rush-02 ${NB}
	say -v Alex ${NB}
fi
