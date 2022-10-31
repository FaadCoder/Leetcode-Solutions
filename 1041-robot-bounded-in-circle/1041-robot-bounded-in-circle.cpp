class Solution
{
    enum Direction
    {
        North,
        East,
        South,
        West
    };

    vector<Direction> directions = 
    { 
        North,
        East,
        South,
        West
    };

    void turnLeft(Direction & currentDirection)
    {
        currentDirection = directions[(currentDirection + 3) % 4];
    }

    void turnRight(Direction & currentDirection)
    {
        currentDirection = directions[(currentDirection + 1) % 4];
    }

    void goStraight(Direction direction, int &dirX, int &dirY)
    {
        switch (direction)
        {
            case North:
                dirY -= 1;
                break;
            case South:
                dirY += 1;
                break;
            case East:
                dirX += 1;
                break;
            case West:
                dirX -= 1;
                break;
        }
    }

    public:
        bool isRobotBounded(string instructions)
        {
            int dirX = 0, dirY = 0;
            Direction currentDirection = North;

            for (char &ch: instructions)
            {
                if (ch == 'G')
                    goStraight(currentDirection, dirX, dirY);
                else if (ch == 'L')
                    turnLeft(currentDirection);
                else
                    turnRight(currentDirection);
            }

            return ((dirX == 0 and dirY == 0) or (currentDirection != North));
        }
};