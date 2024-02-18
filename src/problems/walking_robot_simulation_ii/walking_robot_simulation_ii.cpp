#include <algorithm>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Robot {
    int _width;
    int _height;

    enum class Direction {
        NORTH,
        EAST,
        SOUTH,
        WEST
    };

    int _x = 0;
    int _y = 0;
    Direction _direction = Direction::EAST;

    int _queued_steps = 0;

public:
    Robot(int width, int height) : _width{width}, _height{height}
    {}

    void step(int num) {
        _queued_steps += num;
    }

    vector<int> getPos() {
        do_queued_steps();
        return {_x, _y};
    }

    string getDir() {
        do_queued_steps();
        switch (_direction)
        {
            case Direction::NORTH: return "North";
            case Direction::EAST: return "East";
            case Direction::SOUTH: return "South";
            case Direction::WEST: return "West";
        }
    }

private:
    void do_queued_steps() {
        int to_move = std::min(_queued_steps, distance_to_wall(_direction));

        switch (_direction)
        {
            case Direction::NORTH: _y += to_move; break;
            case Direction::EAST: _x += to_move; break;
            case Direction::SOUTH: _y -= to_move; break;
            case Direction::WEST: _x -= to_move; break;
        }

        _queued_steps -= to_move;
        _queued_steps = reduce_steps(_queued_steps);

        if (_queued_steps > 0) {
            rotate();
            do_queued_steps();
        }
    }

    int distance_to_wall(Direction direction) const
    {
        switch (_direction)
        {
            case Direction::NORTH: return _height - (_y + 1);
            case Direction::EAST: return _width - (_x + 1);
            case Direction::SOUTH: return _y;
            case Direction::WEST: return _x;
        }
    }

    void rotate()
    {
        switch (_direction)
        {
            case Direction::NORTH: _direction = Direction::WEST; break;
            case Direction::WEST: _direction = Direction::SOUTH; break;
            case Direction::SOUTH: _direction = Direction::EAST; break;
            case Direction::EAST: _direction = Direction::NORTH; break;
        }
    }

    int reduce_steps(int steps) const
    {
        if (_width < 3 || _height < 3) {
            return steps % (_height * _width);
        } else {
            return steps % (_height * _width - ((_height - 2) * (_width - 2)));
        }
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
