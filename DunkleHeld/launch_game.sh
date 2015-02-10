l1="resources/levels/finished/entrance.xml"
l2="resources/levels/finished/main_hall_phase1.xml"
l3="resources/levels/finished/main_hall_left_phase1.xml"

if [[ $1 == 1 ]]; then
	l=$l1;
fi
if [[ $1 == 2 ]]; then
	l=$l2;
fi
if [[ $1 == 3 ]]; then
	l=$l3;
fi



./dist/Debug/GNU-Linux-x86/dunkleheld $l