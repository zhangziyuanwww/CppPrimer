#include "Message.h"
#include <iostream>

void swap(Message &lhs, Message &rhs)
{
	using std::swap;
	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f->remMsg(&rhs);

	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);

	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders)
{
	add_to_Folders(m);
}

Message::~Message()
{
	remove_from_Folders();
}

void Message::save(Folder &f)
{
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder &f)
{
	folders.erase(&f);
	f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
	for (auto f : m.folders)
		f->addMsg(this);
}

void Message::remove_from_Folders()
{
	for (auto f : folders)
		f->remMsg(this);
}

Message& Message::operator=(const Message &rhs)
{
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

void Message::print_debug()
{
	std::cout << contents << ": ";
	for (auto f : folders)
		std::cout << f->fldr() << " ";
	std::cout << std::endl;
}

// Folder Implementation

void Folder::add_to_Message(const Folder &f)
{
	for (auto m : f.msgs)
		m->addFldr(this);
}

Folder::Folder(const Folder &f) : name(f.name), msgs(f.msgs)
{
	add_to_Message(f);
}

void Folder::remove_from_Message()
{
	for (auto m : msgs)
		m->remFldr(this);
}

Folder::~Folder()
{
	remove_from_Message();
}

Folder& Folder::operator =(const Folder &rhs)
{
	remove_from_Message();
	name = rhs.name;
	msgs = rhs.msgs;
	add_to_Message(rhs);
	return *this;
}

void Folder::print_debug()
{
	std::cout << name << ": ";
	for (auto m : msgs)
		std::cout << m->msg() << " ";
	std::cout << std::endl;
}