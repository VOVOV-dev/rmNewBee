#pragma once 

#include <atomic>
#include <thread>
#include <chrono>
#include <iostream>

class Taskbase
{
    public:
        Taskbase(int key, std::atomic<int> *p1, std::atomic<int> *p2) : key(key), p1(p1), p2(p2) {};

        int key;
        std::atomic<int> *p1 = nullptr, *p2 = nullptr;
        
        virtual void run() = 0;
        void start();
        void stop();
        virtual void callback(int msg) = 0;
        virtual ~Taskbase() = default;

        std::thread handler;
        std::atomic <bool> finish = false;

};

class Task1 : public Taskbase
{
    public:
        Task1(int key, std::atomic<int> *p1, std::atomic<int> *p2) : Taskbase(key, p1, p2) {};
        void run() override;
        void callback(int msg) override;
       
};

class Task2 : public Taskbase
{
    public:
        int k = 1;
        Task2(int key, std::atomic<int> *p1, std::atomic<int> *p2) : Taskbase(key, p1, p2) {};
        void run() override;
        void callback(int msg) override;

};

class Task3 : public Taskbase
{
    public:
        Task3(int key, std::atomic<int> *p1, std::atomic<int> *p2) : Taskbase(key, p1, p2) {};
        void run() override;
        void callback(int msg) override;

};