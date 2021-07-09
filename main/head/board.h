#ifndef BOARD_H
#define BOARD_H

#include "subject.h"

#include <QVector>
#include <QString>

class Tile;

// 枚举类型变量方向
enum Direction { UP, DOWN, LEFT, RIGHT };

// 背景版类
class Board : public Subject
{
public:

    Board(int dimension);
    Board(const Board& other);
    // destroy board
    ~Board();
    // 每次游戏开始时，版面上随机两处为2
    void reset();
    Tile* getTile(int i, int j); //获取棋子的坐标x，y
    int getDimension() const { return dimension; }
    void move(Direction direction); //进行一次移动操作
    bool full() const; //判断棋盘是否已满
    int getPointsScoredLastRound() const { return pointsScoredLastRound; } // 获取上一轮的分数
    bool isTileCollisionLastRound() const { return tileCollisionLastRound; } //上一轮操作时棋子是否碰撞
    bool movePossible() const;

private:
    //qvector实现二维数组board
    QVector<QVector<Tile*> > board;
    int dimension; //维度


    // 创建空白版面
    void init();

    // 在版面上生成随机位置
    QVector<int> freePosition();

    // 如果当前版面状态和参数不一致返回true，判断是否改变
    bool changed(Board& other) const;
    //是否在边界
    bool inbounds(int i, int j);

    // 执行移动操作，调用tileCollision & pointsScoredLastRound
    void moveHorizontally(int i, int j, Direction dir);
    void moveVertically(int i, int j, Direction dir);
    void handleCollision(int i, int j);


    // 下一次移动前的准备
    void prepareForNextMove();

    int pointsScoredLastRound;
    bool tileCollisionLastRound;
};

#endif // BOARD_H
