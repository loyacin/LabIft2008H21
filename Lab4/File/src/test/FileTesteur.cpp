/**
 * \file FileTesteur.cpp
 * \brief Tests de la classe File en format Google Test
 * \author Ludovic Trottier
 * \author Mathieu Dumoulin
 * \version 0.3
 * \date Mai 2014
 *
 * Représentation dans un tableau dynamique
 */

#include "gtest/gtest.h"
#include "../main/File.h"
#include <sstream>

using namespace lab04;
static const int val1 = 10;
static const int val2 = 20;
static const int val3 = 30;

class FileTest: public ::testing::Test {
public:
	virtual void SetUp() {
		file2.enfiler(val1);
		file2.enfiler(val2);
		file2.enfiler(val3);
	}
	// virtual void TearDown() {}
	File<int> file1;
	File<int> file2;
};

TEST_F(FileTest, FileVideOK) {
	EXPECT_TRUE(file1.estVide());
	EXPECT_EQ(0, file1.taille());
}

TEST_F(FileTest, EnfileUnElementOK) {
	file1.enfiler(val1);
	EXPECT_EQ(val1, file1.premier());
	EXPECT_FALSE(file1.estVide());
	EXPECT_EQ(1, file1.taille());
	EXPECT_EQ(val1, file1.defiler());
	EXPECT_TRUE(file1.estVide());
	EXPECT_EQ(0, file1.taille());
}

TEST_F(FileTest, EnfileTroisElementsOK) {
	file1.enfiler(val1);
	EXPECT_EQ(val1, file1.premier());
	EXPECT_EQ(val1, file1.dernier());
	file1.enfiler(val2);
	EXPECT_EQ(val1, file1.premier());
	EXPECT_EQ(val2, file1.dernier());
	file1.enfiler(val3);
	EXPECT_EQ(val1, file1.premier());
	EXPECT_EQ(val3, file1.dernier());

	EXPECT_EQ(val1, file1.defiler());
	EXPECT_EQ(val2, file1.defiler());
	EXPECT_EQ(val3, file1.defiler());
	EXPECT_TRUE(file1.estVide());
}

TEST_F(FileTest, TestCaseOperateurEgal) {
	File<int> autre = file1;

	EXPECT_EQ(autre.taille(), file1.taille());

	autre = file2;

	EXPECT_EQ(autre.taille(), file2.taille());
	EXPECT_EQ(autre.premier(), file2.premier());
	EXPECT_EQ(autre.dernier(), file2.dernier());
}

TEST_F(FileTest, TestCaseConstructeurCopie) {
	File<int> autre2(file1);

	EXPECT_EQ(autre2.taille(), file1.taille());

	File<int> autre(file2);

	EXPECT_EQ(autre.taille(), file2.taille());
	EXPECT_EQ(autre.premier(), file2.premier());
	EXPECT_EQ(autre.dernier(), file2.dernier());
}

TEST_F(FileTest, TestCaseOperateurFlotSortie) {
	std::ostringstream oss;
	oss << file2;

	EXPECT_EQ("[10,20,30,]", oss.str());
}

TEST_F(FileTest, operatorCrochetErreur) {
	file1.enfiler(5);
	EXPECT_THROW(file1[-1], PreconditionException);
	EXPECT_THROW(file1[2], PreconditionException);
}

TEST_F(FileTest, operatorCrochetOk) {
	EXPECT_EQ(val1, file2[0]);
	EXPECT_EQ(val2, file2[1]);
	EXPECT_EQ(val3, file2[2]);
}
