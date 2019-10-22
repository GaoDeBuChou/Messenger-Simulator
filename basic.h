#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class qqUserDGH;
class mBlogUserDGH;
class WeChatUserDGH;
class GroupDGH;
class qqGroupDGH;
class mBlogGroupDGH;
class WeChatGroupDGH;
class qqUsersManagerDGH;
class mBlogManagerDGH;
class WeChatUsersManagerDGH;
class personDGH;

class personDGH {
private:
	int qqid;//qq号，已经注册则与微博一致，否则为0
	int mBlogid; //微博id，已经注册则与qq一致，否则为0
	int Wechatid;//微信id
public:
	void QQID(int i) { qqid = i; }
	void MBLOGID(int i) { mBlogid = i; }
	void WECHATID(int i) { Wechatid = i; }
	qqUserDGH * returnqq();
	mBlogUserDGH * returnmBlog();
	WeChatUserDGH * returnwechat();
};

class UserDGH { //用户
protected:
	int id; //Q号/微信ID （设置：qq10001+ 微信20000+）
	string name; //昵称
	int birthdate; //8位生日
	int registertime; //注册时间（准备调用系统时间实现）
	string place; //所在地
	int number_of_friends; //好友个数
	int number_of_groups; //群个数
public:
	personDGH * person;//使用者
	int ID() { return id; }//输出id
	string Name() { return name; };
	void modify();//修改个人信息
	virtual void AddFriend(int i) = 0;
	virtual void DeleteFriend(int i) = 0;
	virtual void InGroup(int i) = 0;
	virtual void OutGroup(int i) = 0;
	virtual void Show() = 0;
	virtual void Show_Friend() = 0;
	virtual void Show_Group() = 0;
	virtual bool IsFriend(int xid) = 0;///判断是不是好友
	virtual bool IsInGroup(int xid) = 0;//判断是否在群内
	void RegisterTime(int t) { registertime = t; }
	virtual string write() = 0;
};

class qqUserDGH :public UserDGH { //qq用户
private:
	qqUserDGH * friends[100]; //qq好友
	qqGroupDGH * groups[30]; //qq群
public:
	qqUserDGH(int i, string n, int b, string p, int d);
	void AddFriend(int xid);
	void DeleteFriend(int xid);
	void InGroup(int xid);
	void OutGroup(int xid);
	void Show();
	void Show_Friend();
	void Show_Group();
	bool IsFriend(int xid);
	bool IsInGroup(int xid); 
	bool opened; //确实开通则为true，用于检测是不是预留的（未开通，则无法search到）
	string write();
};

class mBlogUserDGH :public UserDGH { //微博用户
private:
	mBlogUserDGH * friends[100]; //微博好友
	mBlogGroupDGH * groups[30]; //微博群
public:
	mBlogUserDGH(int i, string n, int b, string p, int d);
	void AddFriend(int xid);
	void DeleteFriend(int xid);
	void InGroup(int xid);
	void OutGroup(int xid);
	void Show();
	void Show_Friend();
	void Show_Group();
	bool IsFriend(int xid);
	bool IsInGroup(int xid);
	bool opened; //确实开通则为true，用于检测是不是预留的（未开通，则无法search到）
	string write();
};

class WeChatUserDGH :public UserDGH { //微信用户
private:
	WeChatUserDGH * friends[100]; //微信好友
	WeChatGroupDGH * groups[30]; //微信群
public:
	WeChatUserDGH(int i, string n, int b, string p, int d);
	void AddFriend(int xid);
	void DeleteFriend(int xid);
	void InGroup(int xid);
	void OutGroup(int xid);
	void Show();
	void Show_Friend();
	void Show_Group();
	bool IsFriend(int xid);
	bool IsInGroup(int xid);
	string write();
};

class GroupDGH {
protected:
	int ID; //群号（1000+）
	string name;//群名
	int createtime;//创建时间
	int number_of_members;
public:
	int Number_of_members() { return number_of_members; }
	int gID() { return ID; }//输出群号
	string Name() { return name; }
	virtual void Add(int xid) = 0;//加群
	virtual void Kick(int xid) = 0;//退出/踢出
	virtual void Show() = 0;
	virtual bool IsHead(int xid) = 0;
	virtual string write1() = 0;
	virtual string write2() = 0;
};

class qqGroupDGH :public GroupDGH {
private:
	qqUserDGH* GroupMembers[100]; //群员
	qqUserDGH* Head; //群主
	qqUserDGH* Managers[20]; //管理员
	int number_of_managers;
	qqUserDGH* minigroupmembers[15];//临时讨论组
public:
	qqGroupDGH(int i, string n, int x1, int t);//建群，初始一个成员
	void Add(int xid);
	void Kick(int xid);
	void Show();
	bool IsHead(int xid);
	bool IsManager(int xid);
	void BecomeManager(int xid);
	void LostManager(int xid);
	void getinminigroup(int xid);
	void deleteminigroup();
	int number_of_minigroupmembers;
	bool isinminigroup(int xid);
	int MakemBlogGroup();
	int MakeWeChatGroup();
	string write1();
	string write2();
	string write3();
};

class mBlogGroupDGH :public GroupDGH {
private:
	mBlogUserDGH* GroupMembers[100]; //群员
	mBlogUserDGH* Head; //群主
public:
	mBlogGroupDGH(int i, string n, int x1, int t);//建群
	void Add(int xid);
	void Kick(int xid);
	void Show();
	bool IsHead(int xid);
	int Number_of_members() { return number_of_members; }
	int MakeQQGroup();
	int MakeWeChatGroup();
	string write1();
	string write2();
};

class WeChatGroupDGH :public GroupDGH {
private:
	WeChatUserDGH* GroupMembers[100]; //群员
	WeChatUserDGH* Head; //群主
public:
	WeChatGroupDGH(int i, string n, int x1, int t);//建群
	void Add(int xid);
	void Kick(int xid);
	void Show();
	bool IsHead(int xid);
	int Number_of_members() { return number_of_members; }
	int MakeQQGroup();
	int MakemBlogGroup();
	string write1();
	string write2();
};

class UsersManagerDGH {
protected:
	int number_of_users;
	int number_of_groups;
	int friendrelations[200][2]; //好友关系，主要是用于保存记录
	int number_of_relations;
public:
	int Number_of_Users() { return number_of_users; }
	int Number_of_Groups() { return number_of_groups; }
	virtual void Modify(int xid) = 0;
	virtual void AddUser(string n, int b, string p, int d) = 0;
	virtual void AddGroup(string n, int x1, int t) = 0;
	virtual void show(int xid) = 0;
	virtual void show2(int xid) = 0;
	virtual void showfriendlist(int xid) = 0;
	virtual void showgrouplist(int xid) = 0;
	virtual void becomefriends(int x1, int x2) = 0;
	virtual void deletefriends(int x1, int x2) = 0;
	virtual void ingroup(int g1, int x1) = 0;
	virtual void outgroup(int g1, int x1) = 0;
	virtual bool Searching(int xid) = 0;
	virtual bool Searching2(int gid) = 0;
	virtual bool isFriend(int xid, int gid) = 0;
	virtual bool isInGroup(int xid, int gid) = 0;
	virtual bool isHead(int xid, int gid) = 0;
	virtual int Number_of_Members(int gid) = 0;
	virtual string writetofile() = 0;
	virtual string writetofile2() = 0;
};

class qqUsersManagerDGH : public UsersManagerDGH {
private:
	qqUserDGH* qqUsers[200];
	qqGroupDGH* qqGroups[20];
public:
	qqUsersManagerDGH();
	void Modify(int xid) { find(xid)->modify(); }
	void AddUser(string n, int b, string p, int d);
	void AddGroup(string n, int x1, int d);
	qqUserDGH* find(int xid); //根据用户id返回指针
	qqGroupDGH* find2(int xid); //根据群id返回指针
	void show(int xid) { qqUsers[xid - 10001]->Show(); }
	void show2(int xid) { qqGroups[xid - 1001]->Show(); }
	void showfriendlist(int xid) { qqUsers[xid - 10001]->Show_Friend(); }
	void showgrouplist(int xid) { qqUsers[xid - 10001]->Show_Group(); }
	void becomefriends(int x1, int x2);
	void deletefriends(int x1, int x2); 
	void ingroup(int g1, int x1) { find2(g1)->Add(x1); find(x1)->InGroup(g1); }
	void outgroup(int g1, int x1) { find2(g1)->Kick(x1); find(x1)->OutGroup(g1); }
	bool Searching(int xid);
	bool Searching2(int gid);
	bool isFriend(int xid, int gid) { return find(xid)->IsFriend(gid); }
	bool isInGroup(int xid, int gid) { return find(xid)->IsInGroup(gid); }
	bool isHead(int xid, int gid) { return find2(gid)->IsHead(xid); }
	bool isManager(int xid, int gid) { return find2(gid)->IsManager(xid); }
	void becomemanager(int xid, int gid) { find2(gid)->BecomeManager(xid); }
	void lostmanager(int xid, int gid) { find2(gid)->LostManager(xid); }
	void Getinminigroup(int xid, int gid) { find2(gid)->getinminigroup(xid); }
	void Deleteminigroup(int gid) { find2(gid)->deleteminigroup(); }
	bool Isinminigroup(int xid, int gid) { return find2(gid)->isinminigroup(xid); }
	int Number_of_Members(int gid) { return find2(gid)->Number_of_members(); }
	mBlogUserDGH * returnmBlog(int xid) { return find(xid)->person->returnmBlog(); }
	WeChatUserDGH * returnWeChat(int xid) { return find(xid)->person->returnwechat(); }
	void changemblog(int qqid, int mbid) { find(qqid)->person->MBLOGID(mbid); }
	void changewechat(int qqid, int wxid) { find(qqid)->person->WECHATID(wxid); }
	void open(int xid);
	string groupname(int g1) { return find2(g1)->Name(); }
	int makembloggroup(int g1) { return find2(g1)->MakemBlogGroup(); }//返回群号
	int makewechatgroup(int g1) { return find2(g1)->MakeWeChatGroup(); }
	string writetofile();
	string writetofile2();
};

class mBlogManagerDGH : public UsersManagerDGH {
private:
	mBlogUserDGH* mbUsers[200];
	mBlogGroupDGH* mbGroups[20];
public:
	mBlogManagerDGH();
	void Modify(int xid) { find(xid)->modify(); }
	void AddUser(string n, int b, string p, int d);
	void AddGroup(string n, int x1, int d);
	mBlogUserDGH* find(int xid); //根据用户id返回指针
	mBlogGroupDGH* find2(int xid); //根据群id返回指针
	void show(int xid) { mbUsers[xid - 10001]->Show(); }
	void show2(int xid) { mbGroups[xid - 1001]->Show(); }
	void showfriendlist(int xid) { mbUsers[xid - 10001]->Show_Friend(); }
	void showgrouplist(int xid) { mbUsers[xid - 10001]->Show_Group(); }
	void becomefriends(int x1, int x2);
	void deletefriends(int x1, int x2);
	void ingroup(int g1, int x1) { find2(g1)->Add(x1); find(x1)->InGroup(g1); }
	void outgroup(int g1, int x1) { find2(g1)->Kick(x1); find(x1)->OutGroup(g1); }
	bool Searching(int xid);
	bool Searching2(int gid);
	bool isFriend(int xid, int gid) { return find(xid)->IsFriend(gid); }
	bool isInGroup(int xid, int gid) { return find(xid)->IsInGroup(gid); }
	bool isHead(int xid, int gid) { return find2(gid)->IsHead(xid); }
	int Number_of_Members(int gid) { return find2(gid)->Number_of_members(); }
	qqUserDGH * returnqq(int xid) { return find(xid)->person->returnqq(); }
	WeChatUserDGH * returnWeChat(int xid) { return find(xid)->person->returnwechat(); }
	void changeqq(int mbid, int qqid) { find(mbid)->person->QQID(qqid); }
	void changewechat(int mbid, int wxid) { find(mbid)->person->WECHATID(wxid); }
	void open(int xid);
	int makeqqgroup(int g1) { return find2(g1)->MakeQQGroup(); }
	int makewechatgroup(int g1) { return find2(g1)->MakeWeChatGroup(); }
	string writetofile();
	string writetofile2();
};

class WeChatUsersManagerDGH : public UsersManagerDGH {
private:
	WeChatUserDGH* WeChatUsers[200];
	WeChatGroupDGH* WeChatGroups[20];
public:
	WeChatUsersManagerDGH();
	void Modify(int xid) { find(xid)->modify(); }
	void AddUser(string n, int b, string p, int d);
	void AddGroup(string n, int x1, int d);
	WeChatUserDGH* find(int xid); //根据用户id返回指针
	WeChatGroupDGH* find2(int xid); //根据群id返回指针
	void show(int xid) { WeChatUsers[xid - 20001]->Show(); }
	void show2(int xid) { WeChatGroups[xid - 1001]->Show(); }
	void showfriendlist(int xid) { WeChatUsers[xid - 20001]->Show_Friend(); }
	void showgrouplist(int xid) { WeChatUsers[xid - 20001]->Show_Group(); }
	void becomefriends(int x1, int x2);
	void deletefriends(int x1, int x2);
	void ingroup(int g1, int x1) { find2(g1)->Add(x1); find(x1)->InGroup(g1); }
	void outgroup(int g1, int x1) { find2(g1)->Kick(x1); find(x1)->OutGroup(g1); }
	bool Searching(int xid);
	bool Searching2(int gid);
	bool isFriend(int xid, int gid) { return find(xid)->IsFriend(gid); }
	bool isInGroup(int xid, int gid) { return find(xid)->IsInGroup(gid); }
	bool isHead(int xid, int gid) { return find2(gid)->IsHead(xid); }
	int Number_of_Members(int gid) { return find2(gid)->Number_of_members(); }
	qqUserDGH * returnqq(int xid) { return find(xid)->person->returnqq(); }
	mBlogUserDGH * returnmBlog(int xid) { return find(xid)->person->returnmBlog(); } 
	void changeqq(int wxid, int qqid) { find(wxid)->person->QQID(qqid); }
	void changemblog(int wxid, int mbid) { find(wxid)->person->MBLOGID(mbid); }
	int makeqqgroup(int g1) { return find2(g1)->MakeQQGroup(); }
	int makembloggroup(int g1) { return find2(g1)->MakemBlogGroup(); }
	string writetofile();
	string writetofile2();
};
