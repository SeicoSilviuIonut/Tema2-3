#include "Mingi.h"

Mingi::Mingi(const std::string& name) : name_(name.length() > 2 ? name : throw std::invalid_argument("Invalid name length")) {}

const std::string& Mingi::getName() const
{
	return name_;
}

void Mingi::setName(const std::string& name)
{
	assert(name.length() > 2, "invalid name");
	name_ = name;
}
	
const std::size_t& Mingi::getBallNo()
{
	return ballList_.size();
}

void Mingi::addBall(const std::string& sourceName)
{
	assert(sourceName.length() > 2, "invalid name");
	ballList_.push_back(sourceName);
}

Mingi::Mingi(const Mingi& source) : name_(source.name_), ballList_(source.ballList_) {}

Mingi& Mingi::operator=(const Mingi& source)
{
	assert(this != &source);
	name_ = source.name_;
	ballList_ = source.ballList_;

	return *this;
}

Mingi& Mingi::operator=(Mingi&& source)
{
	if (this != &source)
	{
		name_ = source.name_;
		source.name_ = "";

		ballList_ = source.ballList_;
		source.ballList_.clear();
	}

	return *this;
}

void Mingi::show() const
{
	std::cout << "Content of " << name_ << " balls: " << std::endl;
	for (auto ball : ballList_)
		std::cout << ball << std::endl;

	std::cout << std::endl;
}

Mingi::~Mingi()
{
}
