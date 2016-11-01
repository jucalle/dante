make re
./generateur/generateur $1 $2 > map
echo "\nprofondeur:"
time ./profondeur/solver map > dontshow
echo "\nlargeur:"
time ./largeur/solver map > dontshow
echo "\nastar:"
time ./astar/solver map > dontshow
rm dontshow
rm map



