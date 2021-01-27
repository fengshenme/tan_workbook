#ifndef CARDSQL_H
#define CARDSQL_H

#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <time.h>

class CardSql {
public:
    CardSql();
    ~CardSql();
    int addCard(QString cmd);
    int delCard(QString cmd);
    int updateCard(QString cmd);
    int findCard(QString cmd, QSqlQuery& qsqy);

private:
    QSqlDatabase db;
};

#endif // CARDSQL_H
