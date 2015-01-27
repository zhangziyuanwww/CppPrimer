#ifndef CP5_MESSAGE_H_
#define CP5_MESSAGE_H_

#include <string>
#include <set>

class Folder;

class Message
{
	friend void swap(Message &, Message &);
	friend class Folder;
public:
	explicit Message(const std::string &str = "") : contents(str) {}
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();

	void save(Folder&);
	void remove(Folder&);

	const std::string& msg() const { return contents; }
	void print_debug();

private:
	void add_to_Folders(const Message&);
	void remove_from_Folders();

	void addFldr(Folder *f) { folders.insert(f); }
	void remFldr(Folder *f) { folders.erase(f); }

private:
	std::string contents;
	std::set<Folder*> folders;
};

void swap(Message&, Message&);

class Folder {
	friend void swap(Message&, Message&);
	friend class Message;
public:
	explicit Folder(const std::string &str = "") :name(str) {}
	Folder(const Folder &);
	Folder& operator=(const Folder &);
	~Folder();

	const std::string& fldr() const { return name; }
	void print_debug();

private:
	std::string name;
	std::set<Message*> msgs;

	void add_to_Message(const Folder&);
	void remove_from_Message();

	void addMsg(Message *m) { msgs.insert(m); }
	void remMsg(Message *m) { msgs.erase(m); }
};

#endif

