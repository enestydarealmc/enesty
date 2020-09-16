if test ! -f count
then echo 0 > count
fi

if  ln count count.lock
then
	for i in 'seq 1 5';
	do
		n = 'tail -l count'
		expr $n + 1 >> count
	done

	rm count.lock
fi
