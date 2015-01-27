#ifndef CP5_MESSAGE_H_
#define CP5_MESSAGE_H_

#include <string>
#include <set>

class Folder;

class Message
{
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
	void remove_to_Folders();

	void addFldr(Folder *f) { folders.insert(f); }
	void remFldr(Folder *f) { folders.erase(f); }

private:
	std::string contents;
	std::set<Folder*> folders;
};

#endif

