#ifndef MAINGAME_H
#define MAINGAME_H


#include <QObject>                                  //Include QObject so the type is known
#include <QTimer>
#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "playfielditem.h"

class MainGame : public QObject                     //Inherit from QObject
{
    Q_OBJECT                                        //Insert Q_OBJECT Macro, needed by MOC to work
public:
    explicit MainGame(QObject *parent = 0);
    ~MainGame();

    Q_PROPERTY(quint8 lives READ getLives NOTIFY livesChanged)

signals:
    void GameEnded();
    void livesChanged();

public slots:
    void roundElapsed();
    void startGame();
    void stopGame();
    quint8 getLives();

    void liveUp();
    void liveDown();

    void leftPressed();
    void rightPressed();

    void populateEnemies();
    void updatePlayFieldItems();
    void removeEnemy(QObject* enemy);

private:
    QQmlApplicationEngine* engine;


    QTimer* roundTimer;
    QTimer* itemTimer;

    quint8 roundNumber;
    quint8 maxRounds;

    quint8 lives;

    QList<QObject*> Enemies;
    QList<QObject*> Gifts;

};

#endif // MAINGAME_H
