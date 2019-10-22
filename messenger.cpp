#include "pch.h"
#include <iostream>
#include <string>
#include <time.h>
#include <fstream>
#include "basic.h"
using namespace std;

qqUsersManagerXXX a1;
mBlogManagerXXX b1;
WeChatUsersManagerXXX c1;

int main()
{
	char input;
	string temp1, temp2;
	int temp3, temp4, temp5; 
	bool temp6;
	bool login = false; //是否已经登录
	bool manage = false;//是否正在群管理状态
	bool temp = false;
	bool out = false;
	int qq_user_now = 0;//当前qq用户id
	int mb_user_now = 0;//当前微博用户id
	int wx_user_now = 0;//当前微信用户id
	int usingnow = 0;//当前使用平台：1.qq 2.微博 3.微信
	
	int j;
	ifstream record1; //读文件
	ofstream record2; //写文件
	record1.open("record.txt");

	//以下为读取QQ信息
	record1 >> temp5; //读入用户个数
	for (j = 0; j < temp5; j++) {
		record1 >> temp1 >> temp3 >> temp2 >> temp4 >> temp6;//昵称、生日、地点、注册时间、open与否
		a1.AddUser(temp1, temp3, temp2, temp4);
		if (temp6) a1.open(j + 10001);
	}
	do { //好友信息
		record1 >> temp3;
		if (temp3 == 0) break;
		record1 >> temp4;
		if (temp4 == 0) break;
		a1.becomefriends(temp3, temp4);
	} while (1);
	record1 >> temp5; //读入群个数
	for (j = 0; j < temp5; j++) {
		record1 >> temp1 >> temp3 >> temp4;//名称、群主、创建时间
		a1.AddGroup(temp1, temp3, temp4);
	}
	do { //加入群
		record1 >> temp3; //群号
		if (temp3 == 0) break;
		record1 >> temp4; //群友
		if (temp4 == 0) break;
		a1.ingroup(temp3, temp4);
	} while (1);
	do { //QQ群管理员
		record1 >> temp3; //群号
		if (temp3 == 0) break;
		record1 >> temp4; //群友
		if (temp4 == 0) break;
		a1.becomemanager(temp4, temp3);
	} while (1);

	//以下为读取微博信息
	record1 >> temp5; //读入用户个数
	for (j = 0; j < temp5; j++) {
		record1 >> temp1 >> temp3 >> temp2 >> temp4 >> temp6;//昵称、生日、地点、注册时间、open与否
		b1.AddUser(temp1, temp3, temp2, temp4);
		if (temp6) b1.open(j + 10001);
	}
	do { //好友信息
		record1 >> temp3;
		if (temp3 == 0) break;
		record1 >> temp4;
		if (temp4 == 0) break;
		b1.becomefriends(temp3, temp4);
	} while (1);
	record1 >> temp5; //读入群个数
	for (j = 0; j < temp5; j++) {
		record1 >> temp1 >> temp3 >> temp4;//名称、群主、创建时间
		b1.AddGroup(temp1, temp3, temp4);
	}
	do { //加入群
		record1 >> temp3; //群号
		if (temp3 == 0) break;
		record1 >> temp4; //群友
		if (temp4 == 0) break;
		b1.ingroup(temp3, temp4);
	} while (1);

	//以下为读取微信信息
	record1 >> temp5; //读入用户个数
	for (j = 0; j < temp5; j++) {
		record1 >> temp1 >> temp3 >> temp2 >> temp4;//昵称、生日、地点、注册时间
		c1.AddUser(temp1, temp3, temp2, temp4);
	}
	do { //好友信息
		record1 >> temp3;
		if (temp3 == 0) break;
		record1 >> temp4;
		if (temp4 == 0) break;
		c1.becomefriends(temp3, temp4);
	} while (1);
	record1 >> temp5; //读入群个数
	for (j = 0; j < temp5; j++) {
		record1 >> temp1 >> temp3 >> temp4;//名称、群主、创建时间
		c1.AddGroup(temp1, temp3, temp4);
	}
	do { //加入群
		record1 >> temp3; //群号
		if (temp3 == 0) break;
		record1 >> temp4; //群友
		if (temp4 == 0) break;
		c1.ingroup(temp3, temp4);
	} while (1);

	//以下为绑定部分
	do { 
		record1 >> temp3; //QQ
		if (temp3 == 0) break;
		record1 >> temp4; //微博
		if (temp4 == 0) break;
		a1.changemblog(temp3, temp4);
	} while (1);
	do {
		record1 >> temp3; //QQ
		if (temp3 == 0) break;
		record1 >> temp4; //微信
		if (temp4 == 0) break;
		a1.changewechat(temp3, temp4);
	} while (1);
	do {
		record1 >> temp3; //微博
		if (temp3 == 0) break;
		record1 >> temp4; //QQ
		if (temp4 == 0) break;
		b1.changeqq(temp3, temp4);
	} while (1);
	do {
		record1 >> temp3; //微博
		if (temp3 == 0) break;
		record1 >> temp4; //微信
		if (temp4 == 0) break;
		b1.changewechat(temp3, temp4);
	} while (1);
	do {
		record1 >> temp3; //微信
		if (temp3 == 0) break;
		record1 >> temp4; //QQ
		if (temp4 == 0) break;
		c1.changeqq(temp3, temp4);
	} while (1);
	do {
		record1 >> temp3; //微信
		if (temp3 == 0) break;
		record1 >> temp4; //微博
		if (temp4 == 0) break;
		c1.changemblog(temp3, temp4);
	} while (1);

	struct tm timenow;   //tm结构指针
	time_t now;  //声明time_t类型变量
	time(&now);      //获取系统日期和时间
	localtime_s(&timenow, &now);   //获取当地日期和时间
	int date_now = (timenow.tm_year + 1900) * 10000 + (timenow.tm_mon + 1) * 100 + (timenow.tm_mday);

	do {
		cout << "您好！请问您想要注册/登录哪个平台？" << endl << "1.qq 2.微博 3.微信 任意键：退出" << endl;
		cin >> input;
		switch (input) {
		case'1': usingnow = 1; break;
		case'2': usingnow = 2; break;
		case'3': usingnow = 3; break;
		default://结束程序，保存文件 
			record2.open("record.txt");
			record2 << a1.writetofile();
			record2 << b1.writetofile();
			record2 << c1.writetofile();
			record2 << a1.writetofile2();
			record2 << b1.writetofile2();
			record2 << c1.writetofile2();
			record2.close();
			return 0;
		}
		while (usingnow == 1) {
			do {
				cout << "1.登录账号 2.注册一个新账号 其他任意键：退出" << endl;
				cin >> input;
				switch (input) {
				case '1':
					cout << "请输入你的qq号：";
					cin >> temp3;
					if (a1.Searching(temp3)) {
						login = true;
						qq_user_now = temp3;
						cout << "登录成功！" << endl;
						a1.show(temp3);
						if (a1.returnmBlog(temp3) != 0) {
							mb_user_now = a1.returnmBlog(qq_user_now)->ID();
							cout << "微博已经登录，ID为" << mb_user_now << endl;
						}
						else { cout << "未开通微博账号" << endl; }
						if (a1.returnWeChat(temp3) != 0) {
							wx_user_now = a1.returnWeChat(qq_user_now)->ID();
							cout << "微信已经登录，ID为" << wx_user_now << endl;
						}
						else { cout << "未绑定微信账号" << endl; }
					}
					else { cout << "登录失败！" << endl; login = false; }
					break;
				case '2':
					cout << "请输入您的昵称：" << endl;
					cin >> temp1;
					do {
						cout << "请输入您的生日(8位，年月日)：" << endl;
						cin >> temp3;
					} while ((temp3 < 19000101) or (temp3 > 20200101) or (((temp3 % 10000) / 100) > 12) or (((temp3 % 10000) / 100) < 1) or ((temp3 % 100) > 31) or ((temp3 % 100) < 1));
					cout << "请输入您的所在地：" << endl;
					cin >> temp2;
					a1.AddUser(temp1, temp3, temp2, date_now);
					cout << "注册成功！您的qq号为" << a1.Number_of_Users() + 10000 << endl;
					qq_user_now = a1.Number_of_Users() + 10000;
					login = true;
					cout << endl;
					a1.show(a1.Number_of_Users() + 10000);
					cout << "状态：已登录" << endl;
					a1.open(qq_user_now);
					b1.AddUser(temp1, temp3, temp2, date_now);//预留微博id位置（这么做是因为qq与微博号码必须一致）
					break;
				default:
					usingnow = 0; out = true;
				}
			} while ((login == false) && (out == false));
			do {
				if (out) { out = false; break; }
				cout << endl << "接下来您可以：" << endl;
				cout << "1.修改自己的个人信息 2.查看其他用户的个人信息 3.添加好友 4.删除好友 5.查看群信息" << endl
					<< "6.进入群 7.退出群 8.管理群 9.创建群 0.退出" << endl
					<< "a.查看本账号与微博、微信的绑定情况 b.开通微博账号 c.绑定微信账号 d.解除与微信账号的绑定" << endl
					<< "e.查看并添加微博推荐好友 f.查看并添加微信推荐好友" << endl;
				cout << "（注：QQ好友可以直接通过QQ号添加。QQ群可以直接通过群号加入。QQ群临时讨论组退出后不会保存）" << endl;
				cin >> input;
				switch (input) {
				case'1':a1.Modify(qq_user_now); a1.show(qq_user_now); break;
				case'2':
					cout << "请输入用户的qq号：" << endl;
					cin >> temp3;
					if (a1.Searching(temp3)) a1.show(temp3);
					else cout << "找不到该用户！" << endl;
					break;
				case'3':
					a1.showfriendlist(qq_user_now);
					cout << "请输入您希望添加好友的qq号：" << endl;
					cin >> temp3;
					if (a1.isFriend(qq_user_now, temp3)) cout << "已经是好友！" << endl;
					else if (a1.Searching(temp3) == false) cout << "不存在该用户！" << endl;
					else if (temp3 == qq_user_now) cout << "不能添加您自己！" << endl;
					else { a1.becomefriends(qq_user_now, temp3); cout << "已成功添加好友。" << endl; a1.showfriendlist(qq_user_now); }
					break;
				case'4':
					a1.showfriendlist(qq_user_now);
					cout << "请输入您希望删除好友的qq号：" << endl;
					cin >> temp3;
					if (a1.isFriend(qq_user_now, temp3)) { a1.deletefriends(qq_user_now, temp3); cout << "已成功删除好友！" << endl; a1.showfriendlist(qq_user_now); }
					else { cout << "双方不是好友！" << endl; }
					break;
				case'5':
					cout << "请输入群号：" << endl;
					cin >> temp3;
					if (a1.isInGroup(qq_user_now, temp3)) a1.show2(temp3);
					else cout << "您不在群内，无权查看群信息。" << endl;
					break;
				case '6': //QQ群通过输入群号直接加入 微信群通过接受他人邀请加入
					a1.showgrouplist(qq_user_now);
					cout << "请输入要加入群的群号：" << endl;
					cin >> temp3;
					if (a1.isInGroup(qq_user_now, temp3)) cout << "已经在群内！" << endl;
					else if (a1.Searching2(temp3) == false) cout << "不存在该群！" << endl;
					else { a1.ingroup(temp3, qq_user_now); cout << "您已成功加入群。" << endl; a1.showgrouplist(qq_user_now); }
					break;
				case '7':
					a1.showgrouplist(qq_user_now);
					cout << "请输入要退出群的群号：" << endl;
					cin >> temp3;
					if ((a1.isInGroup(qq_user_now, temp3)) and (a1.isHead(qq_user_now, temp3) == false)) {
						a1.outgroup(temp3, qq_user_now); cout << "您已成功退出群。" << endl;
						if (a1.isManager(qq_user_now, temp3)) a1.lostmanager(qq_user_now, temp3);
						a1.showgrouplist(qq_user_now); 
					}
					else if (a1.isHead(qq_user_now, temp3))cout << "群主不能退群。" << endl;
					else cout << "您不在该群。" << endl;
					break;
				case '8':
					a1.showgrouplist(qq_user_now);
					cout << "请输入要管理群的群号：" << endl;
					cin >> temp3;
					if (a1.isInGroup(qq_user_now, temp3)) {
						if (a1.isHead(qq_user_now, temp3)) {
							a1.show2(temp3);
							manage = true;
							do {
								cout << "作为群主，您可以：1.邀请成员加入群 2.踢出群成员 3.任命管理员 4.罢免管理员 5.建立临时讨论组 6.解散临时讨论组" << endl
									<<"7.改变群管理模式为微博群 8.改变群管理方式为微信群 其他任意键退出" << endl;
								cin >> input;
								switch (input) {
								case '1':
									cout << "请输入您希望邀请进群的好友qq号：";
									cin >> temp4;
									if (a1.Searching(temp4) == false) cout << "不存在该用户！" << endl;
									else if (a1.isInGroup(temp4, temp3)) { cout << "他/她已经在群内！" << endl; }
									else if (a1.isFriend(qq_user_now, temp4)) { a1.ingroup(temp3, temp4); cout << "他/她已成功入群！" << endl; a1.show2(temp3); }
									else cout << "您和他/她不是好友。" << endl;
									break;
								case '2':
									cout << "请输入您要踢出的群成员的qq号：";
									cin >> temp4;
									if (a1.Searching(temp4) == false) cout << "不存在该用户！" << endl;
									else if (temp4 == qq_user_now) { cout << "不能踢出自己！" << endl; }
									else if (a1.isInGroup(temp4, temp3)) {
										a1.outgroup(temp3, temp4);
										if (a1.isManager(temp4, temp3)) a1.lostmanager(temp4, temp3);
										cout << "他/她已被您踢出！" << endl;
										a1.show2(temp3);
									}
									else cout << "他/她不在群内。";
									break;
								case '3':
									cout << "请输入你需要任命为管理员的qq号：";
									cin >> temp4;
									if (a1.Searching(temp4) == false) cout << "不存在该用户！" << endl;
									else if (a1.isInGroup(temp4, temp3)) {
										if (a1.isManager(temp4, temp3)) { cout << "他/她已经是管理员了！" << endl; }
										else if (a1.isHead(temp4, temp3)) { cout << "不能任命群主为管理员！" << endl; }
										else { a1.becomemanager(temp4, temp3); cout << "他/她已经被任命为管理员！" << endl; a1.show2(temp3); }
									}
									else cout << "他/她不在群内！" << endl;
									break;
								case '4':
									cout << "请输入你需要撤销管理员的qq号：";
									cin >> temp4;
									if (a1.Searching(temp4) == false) cout << "不存在该用户！" << endl;
									else if (a1.isInGroup(temp4, temp3)) {
										if (a1.isManager(temp4, temp3)) { a1.lostmanager(temp4, temp3); cout << "他/她已经被撤销管理员！" << endl; a1.show2(temp3); }
										else { cout << "他/她不是管理员！" << endl; }
									}
									else cout << "他/她不在群内！" << endl;
									break;
								case'5':
									a1.Deleteminigroup(temp3);
									cout << "请输入临时讨论组的人数(2-15)（作为群主自动加入讨论组）" << endl;
									cin >> temp4;
									if ((temp4 < 2) or (temp4 > 15) or (temp4 > a1.Number_of_Members(temp3))) { cout << "人数不符合要求。" << endl; break; }
									a1.Getinminigroup(qq_user_now, temp3);
									int i;
									for (i = 1; i < temp4; i++) {
										do {
											cout << "请输入下一位加入群员的qq号（输入0：放弃建立临时讨论组）" << endl;
											cin >> temp5;
											if (temp5 == 0) { i = 100; a1.Deleteminigroup(temp3); break; }//强行跳出循环
											if (a1.Searching(temp5) == false) cout << "不存在该用户！" << endl;
											else if (a1.isInGroup(temp5, temp3) == false) cout << "不在群内！" << endl;
											else if (a1.Isinminigroup(temp5, temp3) == true) cout << "已经在临时讨论组内！" << endl;
											else {
												temp = true;
												a1.Getinminigroup(temp5, temp3);
											}
										} while (temp == false);
										temp = false;
									}
									a1.show2(temp3);
									break;
								case'6':
									a1.Deleteminigroup(temp3);
									cout << "已经解散临时讨论组！" << endl;
									break;
								case'7':
									cout << "注：本功能可以新建一个微博群，群成员与本QQ群相同（只有开通微博的群员可入群）" << endl;
									if (mb_user_now == 0) cout << "你未开通微博，不能使用此功能！" << endl;
									else {
										temp4 = a1.makembloggroup(temp3); 
										cout << "创建成功！" << endl;
										b1.show2(temp4);
									}
									break;
								case'8':
									cout << "注：本功能可以新建一个微信群，群成员与本QQ群相同（只有绑定微信的群员可入群）" << endl;
									if (wx_user_now == 0) cout << "你未绑定微信，不能使用此功能！" << endl;
									else {
										temp4 = a1.makewechatgroup(temp3);
										cout << "创建成功！" << endl;
										c1.show2(temp4);
									}
									break;
								default:manage = false;
								}
							} while (manage == true);
						}
						else if (a1.isManager(qq_user_now, temp3)) {
							a1.show2(temp3);
							manage = true;
							do {
								cout << "作为管理员，您可以：1.邀请成员加入群 2.踢出群成员 其他任意键退出" << endl;
								cin >> input;
								switch (input) {
								case '1':
									cout << "请输入您希望邀请进群的好友qq号：";
									cin >> temp4;
									if (a1.Searching(temp4) == false) cout << "不存在该用户！" << endl;
									else if (a1.isInGroup(temp4, temp3)) { cout << "他/她已经在群内！" << endl; }
									else if (a1.isFriend(qq_user_now, temp4)) { a1.ingroup(temp3, temp4); cout << "他/她已成功入群！" << endl; a1.show2(temp3); }
									else cout << "您和他/她不是好友。" << endl;
									break;
								case '2':
									cout << "请输入您要踢出的群成员的qq号：";
									cin >> temp4;
									if (a1.Searching(temp4) == false) cout << "不存在该用户！" << endl;
									else if (a1.isHead(temp4, temp3)) { cout << "你不能踢出群主！" << endl; }
									else if (a1.isManager(temp4, temp3)) { cout << "你不能踢出管理员！" << endl; }
									else if (a1.isInGroup(temp4, temp3) == false) cout << "他/她不在群内。" << endl;
									else { a1.outgroup(temp3, temp4); cout << "他/她已被您踢出！" << endl; a1.show2(temp3); }
									break;
								default:manage = false;
								}
							} while (manage == true);
						}
						else cout << "您不是群主或管理员。" << endl;
					}
					else cout << "您不在该群。" << endl;
					break;
				case'9':
					cout << "请输入新建群的群名：" << endl;
					cin >> temp1;
					a1.AddGroup(temp1, qq_user_now, date_now);
					cout << "建群成功！" << endl;
					a1.show2(a1.Number_of_Groups() + 1000);
					break;
				case'a':
					if (a1.returnmBlog(qq_user_now) != 0) { cout << "开通微博ID为" << mb_user_now << endl; }
					else { cout << "未开通微博账号" << endl; }
					if (a1.returnWeChat(qq_user_now) != 0) { cout << "绑定微信ID为" << wx_user_now << endl; }
					else { cout << "未绑定微信账号" << endl; }
					break;
				case'b':
					if (mb_user_now == 0) {
						cout << "您确定要开通微博账号吗？（微博ID与QQ号完全相同，会自动录入QQ的个人信息。） 1.开通 其他键：不开通" << endl;
						cin >> input;
						if (input == '1') {
							b1.open(qq_user_now);
							mb_user_now = qq_user_now;
							cout << "已成功开通！" << endl;
							b1.show(mb_user_now);
							a1.changemblog(qq_user_now, mb_user_now);
							b1.changeqq(mb_user_now, qq_user_now);
						}
					}
					else { cout << "已开通过微博账号，无需再开通" << endl; }
					break;
				case'c':
					if (wx_user_now == 0) {
						cout << "请输入您要绑定的微信账号？" << endl;
						cin >> temp3;
						if (c1.Searching(temp3)) {
							a1.changewechat(qq_user_now, temp3);
							c1.changeqq(temp3, qq_user_now);
							if (b1.Searching(qq_user_now)) { 
								c1.changemblog(temp3, qq_user_now); 
								b1.changewechat(qq_user_now, temp3);
							}
							wx_user_now = temp3;
							cout << "已成功绑定！" << endl;
						}
						else { cout << "不存在该微信账号！" << endl; }
					}
					else { cout << "已绑定过微信账号，不能再绑定。" << endl; }
					break;
				case'd':
					if (wx_user_now != 0) {
						a1.changewechat(qq_user_now, 0);
						b1.changewechat(qq_user_now, 0);
						c1.changeqq(wx_user_now, 0);
						c1.changemblog(wx_user_now, 0);
						wx_user_now = 0;
						cout << "已解除绑定！" << endl;
					}
					else { cout << "未绑定，不能解除绑定。" << endl; }
					break;
				case'e':
					if (mb_user_now == 0)
						cout << "未开通微博，不能使用本功能" << endl;
					else {
						b1.showfriendlist(mb_user_now);
						cout << "请输入您需要添加为QQ好友的微博好友（输入0退出）：" << endl;
						cin >> temp3;
						if (temp3 == 0) break;
						if (b1.isFriend(mb_user_now, temp3)) {
							if (b1.returnqq(temp3) == 0) cout << "他未开通QQ服务，无法添加。" << endl;
							else { a1.becomefriends(qq_user_now, temp3); cout << "已成功添加好友！" << endl; a1.showfriendlist(qq_user_now); }
						}
						else { cout << "他不是您的微博好友，无法在此添加qq好友。" << endl; }
					}
					break;
				case'f':
					if (wx_user_now == 0)
						cout << "未绑定微信，不能使用本功能" << endl;
					else {
						c1.showfriendlist(wx_user_now);
						cout << "请输入您需要添加为QQ好友的微信好友（输入0退出）：" << endl;
						cin >> temp3;
						if (temp3 == 0) break;
						if (c1.isFriend(wx_user_now, temp3)) {
							if (c1.returnqq(temp3) == 0) cout << "他未绑定QQ账号，无法添加。" << endl;
							else { temp3 = c1.returnqq(temp3)->ID(); a1.becomefriends(qq_user_now, temp3); cout << "已成功添加好友！" << endl; a1.showfriendlist(qq_user_now); }
						}
						else { cout << "他不是您的微博好友，无法在此添加qq好友。" << endl; }
					}
					break;
				case'0':login = false; qq_user_now = 0; mb_user_now = 0; wx_user_now = 0; usingnow = 0; cout << endl; break;
				default:cout << "无效命令！" << endl;
				}
			} while (login == true);
		}
		while (usingnow == 2) {
			do {
				cout << "1.登录账号 2.注册一个新账号 其他任意键：退出" << endl;
				cin >> input;
				switch (input) {
				case '1':
					cout << "请输入你的微博ID：";
					cin >> temp3;
					if (b1.Searching(temp3)) {
						login = true;
						mb_user_now = temp3;
						cout << "登录成功！" << endl;
						b1.show(temp3);
						if (b1.returnqq(temp3) != 0) {
							qq_user_now = b1.returnqq(mb_user_now)->ID();
							cout << "QQ已经登录，号码为" << qq_user_now << endl;
						}
						else { cout << "未开通QQ" << endl; }
						if (b1.returnWeChat(temp3) != 0) {
							wx_user_now = b1.returnWeChat(mb_user_now)->ID();
							cout << "微信已经登录，ID为" << wx_user_now << endl;
						}
						else { cout << "未绑定微信账号" << endl; }
					}
					else { cout << "登录失败！" << endl; login = false; }
					break;
				case '2':
					cout << "请输入您的昵称：" << endl;
					cin >> temp1;
					do {
						cout << "请输入您的生日(8位，年月日)：" << endl;
						cin >> temp3;
					} while ((temp3 < 19000101) or (temp3 > 20200101) or (((temp3 % 10000) / 100) > 12) or (((temp3 % 10000) / 100) < 1) or ((temp3 % 100) > 31) or ((temp3 % 100) < 1));
					cout << "请输入您的所在地：" << endl;
					cin >> temp2;
					b1.AddUser(temp1, temp3, temp2, date_now);
					cout << "注册成功！您的微博ID为" << b1.Number_of_Users() + 10000 << endl;
					mb_user_now = b1.Number_of_Users() + 10000;
					login = true;
					cout << endl;
					b1.show(b1.Number_of_Users() + 10000);
					cout << "状态：已登录" << endl;
					b1.open(mb_user_now);
					a1.AddUser(temp1, temp3, temp2, date_now);//预留qqid位置（这么做是因为qq与微博号码必须一致）
					break;
				default:
					usingnow = 0; out = true;
				}
			} while ((login == false) && (out == false));
			do {
				if (out) { out = false; break; }
				cout << endl << "接下来您可以：" << endl;
				cout << "1.修改自己的个人信息 2.查看其他用户的个人信息 3.添加好友 4.删除好友 5.查看群信息" << endl
					<< "6.邀请好友入群 7.退出群 8.管理群 9.创建群 0.退出" << endl//
					<< "a.查看本账号与QQ、微信的绑定情况 b.开通QQ账号 c.绑定微信账号 d.解除与微信账号的绑定" << endl
					<< "e.查看并添加QQ推荐好友 f.查看并添加微信推荐好友" << endl;
				cout << "（注：微博好友可以直接通过ID添加。微博群需要通过邀请加入。）" << endl;
				cin >> input;
				switch (input) {
				case'1':b1.Modify(mb_user_now); b1.show(mb_user_now); break;
				case'2':
					cout << "请输入用户的微博ID：" << endl;
					cin >> temp3;
					if (b1.Searching(temp3)) b1.show(temp3);
					else cout << "找不到该用户！" << endl;
					break;
				case'3':
					b1.showfriendlist(mb_user_now);
					cout << "请输入您希望添加好友的ID：" << endl;
					cin >> temp3;
					if (b1.isFriend(mb_user_now, temp3)) cout << "已经是好友！" << endl;
					else if (b1.Searching(temp3) == false) cout << "不存在该用户！" << endl;
					else if (temp3 == mb_user_now) cout << "不能添加您自己！" << endl;
					else { b1.becomefriends(mb_user_now, temp3); cout << "已成功添加好友。" << endl; b1.showfriendlist(mb_user_now); }
					break;
				case'4':
					b1.showfriendlist(mb_user_now);
					cout << "请输入您希望删除好友的ID：" << endl;
					cin >> temp3;
					if (b1.isFriend(mb_user_now, temp3)) { b1.deletefriends(mb_user_now, temp3); cout << "已成功删除好友！" << endl; b1.showfriendlist(mb_user_now); }
					else { cout << "双方不是好友！" << endl; }
					break;
				case'5':
					cout << "请输入群号：" << endl;
					cin >> temp3;
					if (b1.isInGroup(mb_user_now, temp3)) b1.show2(temp3);
					else cout << "您不在群内，无权查看群信息。" << endl;
					break;
					//QQ群通过输入群号直接加入 微信群通过接受他人邀请加入
				case'6':
					b1.showgrouplist(mb_user_now);
					cout << "请输入群号：";
					cin >> temp3;
					if (b1.isInGroup(mb_user_now, temp3)) {
						cout << "请输入您希望邀请进群的好友ID：";
						cin >> temp4;
						if (b1.Searching(temp4) == false) cout << "不存在该用户！" << endl;
						else if (b1.isInGroup(temp4, temp3)) { cout << "他/她已经在群内！" << endl; }
						else if (b1.isFriend(mb_user_now, temp4)) { b1.ingroup(temp3, temp4); cout << "他/她已成功入群！" << endl; b1.show2(temp3); }
						else cout << "您和他/她不是好友。" << endl;
					}
					else cout << "您不在该群内，无法邀请。" << endl;
					break;
				case '7':
					b1.showgrouplist(mb_user_now);
					cout << "请输入要退出群的群号：" << endl;
					cin >> temp3;
					if ((b1.isInGroup(mb_user_now, temp3)) and (b1.isHead(mb_user_now, temp3) == false)) {	
						b1.outgroup(temp3, mb_user_now); 
						cout << "您已成功退出群。" << endl; 
						b1.showgrouplist(mb_user_now); 
					}
					else if (b1.isHead(mb_user_now, temp3))cout << "群主不能退群。" << endl;
					else cout << "您不在该群。" << endl;
					break;
				case '8':
					b1.showgrouplist(mb_user_now);
					cout << "请输入要管理群的群号：" << endl;
					cin >> temp3;
					if (b1.isInGroup(mb_user_now, temp3)) {
						if (b1.isHead(mb_user_now, temp3)) {
							b1.show2(temp3);
							manage = true;
							do {
								cout << "作为群主，您可以：1.邀请成员加入群 2.踢出群成员" << endl
									<< "7.改变群管理模式为QQ群 8.改变群管理方式为微信群 其他任意键退出" << endl;
								cin >> input;
								switch (input) {
								case '1':
									cout << "请输入您希望邀请进群的好友的ID：";
									cin >> temp4;
									if (b1.Searching(temp4) == false) cout << "不存在该用户！" << endl;
									else if (b1.isInGroup(temp4, temp3)) { cout << "他/她已经在群内！" << endl; }
									else if (b1.isFriend(mb_user_now, temp4)) { b1.ingroup(temp3, temp4); cout << "他/她已成功入群！" << endl; b1.show2(temp3); }
									else cout << "您和他/她不是好友。" << endl;
									break;
								case '2':
									cout << "请输入您要踢出的群成员的ID：";
									cin >> temp4;
									if (b1.Searching(temp4) == false) cout << "不存在该用户！" << endl;
									else if (temp4 == mb_user_now) { cout << "不能踢出自己！" << endl; }
									else if (b1.isInGroup(temp4, temp3)) {
										b1.outgroup(temp3, temp4);
										cout << "他/她已被您踢出！" << endl;
										b1.show2(temp3);
									}
									else cout << "他/她不在群内。";
									break;
								case'7':
									cout << "注：本功能可以新建一个QQ群，群成员与本微博群相同（只有开通QQ的群员可入群）" << endl;
									if (qq_user_now == 0) cout << "你未开通QQ，不能使用此功能！" << endl;
									else {
										temp4 = b1.makeqqgroup(temp3);
										cout << "创建成功！" << endl;
										a1.show2(temp4);
									}
									break;
								case'8':
									cout << "注：本功能可以新建一个微信群，群成员与本微博群相同（只有绑定微信的群员可入群）" << endl;
									if (wx_user_now == 0) cout << "你未绑定微信，不能使用此功能！" << endl;
									else {
										temp4 = b1.makewechatgroup(temp3);
										cout << "创建成功！" << endl;
										c1.show2(temp4);
									}
									break;
								default:manage = false;
								}
							} while (manage == true);
						}
						else cout << "您不是群主。" << endl;
					}
					else cout << "您不在该群。" << endl;
					break;
				case'9':
					cout << "请输入新建群的群名：" << endl;
					cin >> temp1;
					b1.AddGroup(temp1, mb_user_now, date_now);
					cout << "建群成功！" << endl;
					b1.show2(b1.Number_of_Groups() + 1000);
					break;
				case'a':
					if (b1.returnqq(mb_user_now) != 0) { cout << "开通QQ号为" << qq_user_now << endl; }
					else { cout << "未开通QQ" << endl; }
					if (b1.returnWeChat(mb_user_now) != 0) { cout << "绑定微信ID为" << wx_user_now << endl; }
					else { cout << "未绑定微信账号" << endl; }
					break;
				case'b':
					if (qq_user_now == 0) {
						cout << "您确定要开通QQ账号吗？（微博ID与QQ号完全相同，会自动录入QQ的个人信息。） 1.开通 其他键：不开通" << endl;
						cin >> input;
						if (input == '1') {
							a1.open(mb_user_now);
							qq_user_now = mb_user_now;
							cout << "已成功开通！" << endl;
							a1.show(qq_user_now);
							b1.changeqq(mb_user_now, qq_user_now);
							a1.changemblog(qq_user_now, mb_user_now);
						}
					}
					else { cout << "已开通过QQ账号，无需再开通" << endl; }
					break;
				case'c':
					if (wx_user_now == 0) {
						cout << "请输入您要绑定的微信账号？" << endl;
						cin >> temp3;
						if (c1.Searching(temp3)) {
							b1.changewechat(mb_user_now, temp3);
							c1.changemblog(temp3, mb_user_now);
							if (a1.Searching(mb_user_now)) {
								a1.changewechat(mb_user_now, temp3);
								c1.changeqq(temp3, mb_user_now);
							}
							wx_user_now = temp3;
							cout << "已成功绑定！" << endl;
						}
						else { cout << "不存在该微信账号！" << endl; }
					}
					else { cout << "已绑定过微信账号，不能再绑定。" << endl; }
					break;
				case'd':
					if (wx_user_now != 0) {
						b1.changewechat(mb_user_now, 0);
						a1.changewechat(mb_user_now, 0);
						c1.changeqq(wx_user_now, 0);
						c1.changemblog(wx_user_now, 0);
						wx_user_now = 0;
						cout << "已解除绑定！" << endl;
					}
					else { cout << "未绑定，不能解除绑定。" << endl; }
					break;
				case'e':
					if (qq_user_now == 0)
						cout << "未开通QQ，不能使用本功能" << endl;
					else {
						a1.showfriendlist(qq_user_now);
						cout << "请输入您需要添加为微博好友的QQ好友（输入0退出）：" << endl;
						cin >> temp3;
						if (temp3 == 0) break;
						if (a1.isFriend(qq_user_now, temp3)) {
							if (a1.returnmBlog(temp3) == 0) cout << "他未开通微博服务，无法添加。" << endl;
							else { b1.becomefriends(qq_user_now, temp3); cout << "已成功添加好友！" << endl; b1.showfriendlist(mb_user_now); }
						}
						else { cout << "他不是您的QQ好友，无法在此添加微博好友。" << endl; }
					}
					break;
				case'f':
					if (wx_user_now == 0)
						cout << "未绑定微信，不能使用本功能" << endl;
					else {
						c1.showfriendlist(wx_user_now);
						cout << "请输入您需要添加为微博好友的微信好友（输入0退出）：" << endl;
						cin >> temp3;
						if (temp3 == 0) break;
						if (c1.isFriend(wx_user_now, temp3)) {
							if (c1.returnmBlog(temp3) == 0) cout << "他未绑定微博账号，无法添加。" << endl;
							else { temp3 = c1.returnmBlog(temp3)->ID(); b1.becomefriends(mb_user_now, temp3); cout << "已成功添加好友！" << endl; b1.showfriendlist(mb_user_now); }
						}
						else { cout << "他不是您的微信好友，无法在此添加微博好友。" << endl; }
					}
					break;
				case'0':login = false; qq_user_now = 0; mb_user_now = 0; wx_user_now = 0; usingnow = 0; cout << endl; break;
				default:cout << "无效命令！" << endl;
				}
			} while (login == true);
		}
		while (usingnow == 3) {
			do {
				cout << "1.登录账号 2.注册一个新账号 其他任意键：退出" << endl;
				cin >> input;
				switch (input) {
				case '1':
					cout << "请输入你的微信ID：";
					cin >> temp3;
					if (c1.Searching(temp3)) {
						login = true;
						wx_user_now = temp3;
						cout << "登录成功！" << endl;
						c1.show(temp3);
						if (c1.returnqq(temp3) != 0) {
							qq_user_now = c1.returnqq(wx_user_now)->ID();
							cout << "QQ已经登录，号码为" << qq_user_now << endl;
						}
						else { cout << "未绑定QQ号" << endl; }
						if (c1.returnmBlog(temp3) != 0) {
							mb_user_now = c1.returnmBlog(wx_user_now)->ID();
							cout << "微博已经登录，ID为" << mb_user_now << endl;
						}
						else { cout << "未绑定微博账号" << endl; }
					}
					else { cout << "登录失败！" << endl; login = false; }
					break;
				case '2':
					cout << "请输入您的昵称：" << endl;
					cin >> temp1;
					do {
						cout << "请输入您的生日(8位，年月日)：" << endl;
						cin >> temp3;
					} while ((temp3 < 19000101) or (temp3 > 20200101) or (((temp3 % 10000) / 100) > 12) or (((temp3 % 10000) / 100) < 1) or ((temp3 % 100) > 31) or ((temp3 % 100) < 1));
					cout << "请输入您的所在地：" << endl;
					cin >> temp2;
					c1.AddUser(temp1, temp3, temp2, date_now);
					cout << "注册成功！您的微信ID为" << c1.Number_of_Users() + 20000 << endl;
					wx_user_now = c1.Number_of_Users() + 20000;
					login = true;
					cout << endl;
					c1.show(c1.Number_of_Users() + 20000);
					cout << "状态：已登录" << endl;
					break;
				default:
					usingnow = 0; out = true;
				}
			} while ((login == false) && (out == false));
			do {
				if (out) { out = false; break; }
				cout << endl << "接下来您可以：" << endl;
				cout << "1.修改自己的个人信息 2.查看其他用户的个人信息 3.添加好友 4.删除好友 5.查看群信息" << endl
					<< "6.邀请好友入群 7.退出群 8.管理群 9.创建群 0.退出" << endl
					<< "a.查看本账号与QQ号的绑定情况 b.绑定QQ号 c.解除与QQ号的绑定" << endl //一个QQ号（包括QQ、微博）只能绑定一个微信！
					<< "e.查看并添加QQ推荐好友 f.查看并添加微博推荐好友" << endl;
				cout << "（注：微信好友可以直接通过ID添加。微信群需要通过邀请加入。）" << endl;
				cin >> input;
				switch (input) {
				case'1':c1.Modify(wx_user_now); c1.show(wx_user_now); break;
				case'2':
					cout << "请输入用户的微信ID：" << endl;
					cin >> temp3;
					if (c1.Searching(temp3)) c1.show(temp3);
					else cout << "找不到该用户！" << endl;
					break;
				case'3':
					c1.showfriendlist(wx_user_now);
					cout << "请输入您希望添加好友的ID：" << endl;
					cin >> temp3;
					if (c1.isFriend(wx_user_now, temp3)) cout << "已经是好友！" << endl;
					else if (c1.Searching(temp3) == false) cout << "不存在该用户！" << endl;
					else if (temp3 == wx_user_now) cout << "不能添加您自己！" << endl;
					else { c1.becomefriends(wx_user_now, temp3); cout << "已成功添加好友。" << endl; c1.showfriendlist(wx_user_now); }
					break;
				case'4':
					c1.showfriendlist(wx_user_now);
					cout << "请输入您希望删除好友的ID：" << endl;
					cin >> temp3;
					if (c1.isFriend(wx_user_now, temp3)) { c1.deletefriends(wx_user_now, temp3); cout << "已成功删除好友！" << endl; c1.showfriendlist(wx_user_now); }
					else { cout << "双方不是好友！" << endl; }
					break;
				case'5':
					cout << "请输入群号：" << endl;
					cin >> temp3;
					if (c1.isInGroup(wx_user_now, temp3)) c1.show2(temp3);
					else cout << "您不在群内，无权查看群信息。" << endl;
					break;
					//QQ群通过输入群号直接加入 微信群通过接受他人邀请加入
				case'6':
					c1.showgrouplist(wx_user_now);
					cout << "请输入群号：";
					cin >> temp3;
					if (c1.isInGroup(wx_user_now, temp3)) {
						cout << "请输入您希望邀请进群的好友ID：";
						cin >> temp4;
						if (c1.Searching(temp4) == false) cout << "不存在该用户！" << endl;
						else if (c1.isInGroup(temp4, temp3)) { cout << "他/她已经在群内！" << endl; }
						else if (c1.isFriend(wx_user_now, temp4)) { c1.ingroup(temp3, temp4); cout << "他/她已成功入群！" << endl; c1.show2(temp3); }
						else cout << "您和他/她不是好友。" << endl;
					}
					else cout << "您不在该群内，无法邀请。" << endl;
					break;
				case '7':
					c1.showgrouplist(wx_user_now);
					cout << "请输入要退出群的群号：" << endl;
					cin >> temp3;
					if ((c1.isInGroup(wx_user_now, temp3)) and (c1.isHead(wx_user_now, temp3) == false))
						{ c1.outgroup(temp3, wx_user_now); cout << "您已成功退出群。" << endl; c1.showgrouplist(wx_user_now);}
					else if (c1.isHead(wx_user_now, temp3))cout << "群主不能退群。" << endl;
					else cout << "您不在该群。" << endl;
					break;
				case '8':
					c1.showgrouplist(wx_user_now);
					cout << "请输入要管理群的群号：" << endl;
					cin >> temp3;
					if (c1.isInGroup(wx_user_now, temp3)) {
						if (c1.isHead(wx_user_now, temp3)) {
							c1.show2(temp3);
							manage = true;
							do {
								cout << "作为群主，您可以：1.邀请成员加入群 2.踢出群成员" << endl
									<< "7.改变群管理模式为QQ群 8.改变群管理方式为微信群 其他任意键退出" << endl;
								cin >> input;
								switch (input) {
								case '1':
									cout << "请输入您希望邀请进群的好友的ID：";
									cin >> temp4;
									if (c1.Searching(temp4) == false) cout << "不存在该用户！" << endl;
									else if (c1.isInGroup(temp4, temp3)) { cout << "他/她已经在群内！" << endl; }
									else if (c1.isFriend(wx_user_now, temp4)) { c1.ingroup(temp3, temp4); cout << "他/她已成功入群！" << endl; c1.show2(temp3); }
									else cout << "您和他/她不是好友。" << endl;
									break;
								case '2':
									cout << "请输入您要踢出的群成员的ID：";
									cin >> temp4;
									if (c1.Searching(temp4) == false) cout << "不存在该用户！" << endl;
									else if (temp4 == wx_user_now) { cout << "不能踢出自己！" << endl; }
									else if (c1.isInGroup(temp4, temp3)) {
										c1.outgroup(temp3, temp4);
										cout << "他/她已被您踢出！" << endl;
										c1.show2(temp3);
									}
									else cout << "他/她不在群内。";
								case'7':
									cout << "注：本功能可以新建一个QQ群，群成员与本微信群相同（只有绑定QQ的群员可入群）" << endl;
									if (qq_user_now == 0) cout << "你未绑定QQ，不能使用此功能！" << endl;
									else {
										temp4 = c1.makeqqgroup(temp3);
										cout << "创建成功！" << endl;
										a1.show2(temp4);
									}
									break;
								case'8':
									cout << "注：本功能可以新建一个微博群，群成员与本微信群相同（只有绑定微博的群员可入群）" << endl;
									if (mb_user_now == 0) cout << "你未绑定微博，不能使用此功能！" << endl;
									else {
										temp4 = c1.makembloggroup(temp3);
										cout << "创建成功！" << endl;
										b1.show2(temp4);
									}
									break;
									break;
								default:manage = false;
								}
							} while (manage == true);
						}
						else cout << "您不是群主。" << endl;
					}
					else cout << "您不在该群。" << endl;
					break;
				case'9':
					cout << "请输入新建群的群名：" << endl;
					cin >> temp1;
					c1.AddGroup(temp1, wx_user_now, date_now);
					cout << "建群成功！" << endl;
					c1.show2(c1.Number_of_Groups() + 1000);
					break;
				case'a':
					if (c1.returnqq(wx_user_now) != 0) { cout << "绑定QQ号为" << qq_user_now << endl; }
					else if (c1.returnmBlog(wx_user_now) != 0) { cout << "绑定QQ号为" << mb_user_now << endl; }
					else { cout << "未绑定QQ号" << endl; }
					break;
				case'b':
					if ((qq_user_now == 0) && (mb_user_now == 0)) {
						cout << "请输入您要绑定的QQ号？" << endl;
						cin >> temp3;
						if (a1.Searching(temp3)) {
							a1.changewechat(temp3, wx_user_now);
							c1.changeqq(wx_user_now, temp3);
							qq_user_now = temp3;
							if (b1.Searching(temp3)) { 						
								b1.changewechat(temp3, wx_user_now);							
								c1.changemblog(wx_user_now, temp3);
								mb_user_now = temp3;
							}
							cout << "已成功绑定！" << endl;
						}
						else if (b1.Searching(temp3)) {
							b1.changewechat(temp3, wx_user_now);
							c1.changemblog(wx_user_now, temp3);
							mb_user_now = temp3;
							if (a1.Searching(temp3)) { 
								a1.changewechat(temp3, wx_user_now); 
								qq_user_now = temp3; 							
								c1.changeqq(wx_user_now, temp3);
							}
							cout << "已成功绑定！" << endl;
						}
						else { cout << "不存在该QQ号！" << endl; }
					}
					else { cout << "已绑定过QQ号，不能再绑定。" << endl; }
					break;
				case'c':
					if ((qq_user_now != 0) || (mb_user_now != 0)) {
						if (qq_user_now != 0) a1.changewechat(qq_user_now, 0);
						if (mb_user_now != 0) b1.changewechat(mb_user_now, 0);
						c1.changeqq(wx_user_now, 0);
						c1.changemblog(wx_user_now, 0);
						qq_user_now = 0;
						mb_user_now = 0;
						cout << "已解除绑定！" << endl;
					}
					else { cout << "未绑定，不能解除绑定。" << endl; }
					break;
				case'e':
					if (qq_user_now == 0)
						cout << "未绑定QQ，不能使用本功能" << endl;
					else {
						a1.showfriendlist(qq_user_now);
						cout << "请输入您需要添加为微信好友的QQ好友（输入0退出）：" << endl;
						cin >> temp3;
						if (temp3 == 0) break;
						if (a1.isFriend(qq_user_now, temp3)) {
							if (a1.returnWeChat(temp3) == 0) cout << "他未开通微信服务，无法添加。" << endl;
							else { temp3 = a1.returnWeChat(temp3)->ID(); c1.becomefriends(wx_user_now, temp3); cout << "已成功添加好友！" << endl; c1.showfriendlist(wx_user_now); }
						}
						else { cout << "他不是您的QQ好友，无法在此添加微信好友。" << endl; }
					}
					break;
				case'f':
					if (mb_user_now == 0)
						cout << "未绑定微博，不能使用本功能" << endl;
					else {
						b1.showfriendlist(qq_user_now);
						cout << "请输入您需要添加为微信好友的微博好友（输入0退出）：" << endl;
						cin >> temp3;
						if (temp3 == 0) break;
						if (b1.isFriend(mb_user_now, temp3)) {
							if (b1.returnWeChat(temp3) == 0) cout << "他未开通微信服务，无法添加。" << endl;
							else { temp3 = b1.returnWeChat(temp3)->ID(); c1.becomefriends(wx_user_now, temp3); cout << "已成功添加好友！" << endl; c1.showfriendlist(wx_user_now); }
						}
						else { cout << "他不是您的微博好友，无法在此添加微信好友。" << endl; }
					}
					break;
				case'0':login = false; qq_user_now = 0; mb_user_now = 0; wx_user_now = 0; usingnow = 0; cout << endl; break;
				default:cout << "无效命令！" << endl;
				}
			} while (login == true);
		}
	}while (1);
}
