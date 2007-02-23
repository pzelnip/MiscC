# originally used with cMake 2.4.1

PROJECT(threadTest)

ADD_EXECUTABLE(threadTest runnable threadTest)

TARGET_LINK_LIBRARIES(threadTest pthread)
