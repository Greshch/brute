#ifndef BRUTE_H
#define BRUTE_H

#include<string>


class Brute
{
    public:
    Brute();
    Brute(size_t buffer);
    std::string& GetPassword();
    void SetList(char from, char to);
    void SetList(std::string const& list);
    size_t GetLength() const;
    void Reset();
    virtual ~Brute();

    protected:
    static const size_t s_length = 32;
    void Increment();
    size_t GetSize() const;
    void SetFirstAndLast();

    private:
    std::string m_password;
    std::string m_list;
    size_t m_index = 0;
    char m_first;
    char m_last;
};

#endif // BRUTE_H
