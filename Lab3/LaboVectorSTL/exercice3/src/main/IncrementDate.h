#ifndef LAB3_INCREMENTDATE_H
#define LAB3_INCREMENTDATE_H

struct Date
{
    int jour;
    int mois;
    int annee;
};

static Date* incrementDate(const Date &date);

#endif //LAB3_INCREMENTDATE_H
