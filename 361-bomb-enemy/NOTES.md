Algorithm:
- Go row by row
- for each row , calculate the number of enemies until you hit any Wall
- For each col, calculare the number Of enemies until you hit any wall
- store the cols result in the vector as it can be reused later
- at every empty cell calculate rowHits+colHits
- Take max of both