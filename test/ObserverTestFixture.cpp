//
// Created by Alessandro on 01/07/2022.
//

#include "gtest/gtest.h"
#include "ObserverClassTest.h"
#include "SubjectClassTest.h"

TEST(ObserverClassTest, RegisterObserverTest) {
    auto* observerTest = new ObserverClassTest;
    auto* observerTest1 = new ObserverClassTest;
    auto* subjectTest = new SubjectClassTest;
    ASSERT_EQ(subjectTest->getObservers().size(), 0);
    subjectTest->registerObserver(observerTest);
    subjectTest->registerObserver(observerTest1);
    ASSERT_EQ(subjectTest->getObservers().size(), 2);
    delete observerTest;
    delete observerTest1;
    delete subjectTest;
}

TEST(ObserverClassTest, RemoveObserverTest){
    auto* observerTest = new ObserverClassTest;
    auto* observerTest1 = new ObserverClassTest;
    auto* subjectTest = new SubjectClassTest;
    subjectTest->registerObserver(observerTest);
    subjectTest->registerObserver(observerTest1);
    ASSERT_EQ(subjectTest->getObservers().size(), 2);
    subjectTest->removeObserver(observerTest);
    subjectTest->removeObserver(observerTest1);
    ASSERT_EQ(subjectTest->getObservers().size(), 0);
    delete observerTest1;
    delete observerTest;
    delete subjectTest;
}