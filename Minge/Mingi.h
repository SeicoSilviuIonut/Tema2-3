#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <assert.h>   

const int BALL_NO = 5;

class Mingi final
{
public:
	Mingi() = delete;
	Mingi(const std::string& name);
	Mingi(const Mingi& source);
	Mingi& operator=(const Mingi& source);

	Mingi& operator=(Mingi&& source);

	void setName(const std::string& name);
	const std::string& getName() const;

	void addBall(const std::string& sourceName);
	const std::size_t& getBallNo();

	void show() const;

	~Mingi();


	std::string name_;
	std::vector<std::string> ballList_;
};

