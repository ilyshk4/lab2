#ifndef TESTS_H
#define TESTS_H

#include <gtest/gtest.h>

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <math.h>
#include <fstream>
#include <cstdio>

extern "C" {
#include "text.h"
#include "common.h"
}

std::string GetText(std::string filename) {
	std::ifstream t(filename);
	std::stringstream buffer;
	buffer << t.rdbuf();
	std::string target = buffer.str();
	return target;
}

TEST(showreveven, DefaultEven) {	
	testing::internal::CaptureStdout();
	
	text txt = create_text();
	load(txt, "tests/input/input1.txt");
	show_rev_even(txt);
	
	std::string output = testing::internal::GetCapturedStdout();
	std::string target = GetText("tests/input/output1.txt");
	
	ASSERT_EQ(output, target);
}

TEST(showreveven, DefaultOdd) {	
	testing::internal::CaptureStdout();
	
	text txt = create_text();
	load(txt, "tests/input/input5.txt");
	show_rev_even(txt);
	
	std::string output = testing::internal::GetCapturedStdout();
	std::string target = GetText("tests/input/output5.txt");
	
	ASSERT_EQ(output, target);
}

TEST(showreveven, NullFile) {
	testing::internal::CaptureStderr();
	
	show_rev_even(NULL);
	
	std::string capturedStderr = testing::internal::GetCapturedStderr();
	ASSERT_NE(capturedStderr, "");
}

TEST(showreveven, EmptyFile) {
	testing::internal::CaptureStderr();
	
	text txt = create_text();
	load(txt, "tests/input/empty.txt");
	show_rev_even(txt);
	
	std::string capturedStderr = testing::internal::GetCapturedStderr();
	ASSERT_NE(capturedStderr, "");
}

TEST(mnlb, Default) {
	testing::internal::CaptureStdout();
	
	text txt = create_text();
	load(txt, "tests/input/input2.txt");
	set_cursor(txt, 0, 0);
	mnlb(txt);
	show(txt);
	
	std::string output = testing::internal::GetCapturedStdout();
	std::string target = GetText("tests/input/output2.txt");
	
	ASSERT_EQ(output, target);
}

TEST(mnlb, NullFile) {
	testing::internal::CaptureStderr();

	mnlb(NULL);
	
	std::string capturedStderr = testing::internal::GetCapturedStderr();
	ASSERT_NE(capturedStderr, "");
}

TEST(mnlb, EmptyFile) {
	testing::internal::CaptureStderr();
	
	text txt = create_text();
	mnlb(txt);
	
	std::string capturedStderr = testing::internal::GetCapturedStderr();
	ASSERT_NE(capturedStderr, "");
}

TEST(mnlb, OneLine) {
	testing::internal::CaptureStderr();
	
	text txt = create_text();
	load(txt, "tests/input/input3.txt");
	set_cursor(txt, 0, 0);
	mnlb(txt);
	
	std::string capturedStderr = testing::internal::GetCapturedStderr();
	ASSERT_NE(capturedStderr, "");
}

TEST(mnlb, LastLine) {
	testing::internal::CaptureStderr();
	
	text txt = create_text();
	load(txt, "tests/input/input4.txt");
	set_cursor(txt, 4, 0);
	mnlb(txt);
	
	std::string capturedStderr = testing::internal::GetCapturedStderr();
	ASSERT_NE(capturedStderr, "");
}

TEST(set_cursor, Default) {
	testing::internal::CaptureStdout();
	
	text txt = create_text();
	load(txt, "tests/input/input6.txt");
	set_cursor(txt, 1, 3);
	show(txt);
	
	std::string output = testing::internal::GetCapturedStdout();
	std::string target = GetText("tests/input/output6.txt");
	
	ASSERT_EQ(output, target);
}

TEST(set_cursor, LineOutOfRange) {
	testing::internal::CaptureStderr();

	text txt = create_text();
	load(txt, "tests/input/input6.txt");
	set_cursor(txt, 9999, 0);
	
	std::string capturedStderr = testing::internal::GetCapturedStderr();
	ASSERT_NE(capturedStderr, "");
}

TEST(set_cursor, PositionOutOfRange) {
	testing::internal::CaptureStderr();

	text txt = create_text();
	load(txt, "tests/input/input6.txt");
	set_cursor(txt, 0, 9999);
	
	std::string capturedStderr = testing::internal::GetCapturedStderr();
	ASSERT_NE(capturedStderr, "");
}

TEST(p, Default) {
	testing::internal::CaptureStdout();
	
	text txt = create_text();
	load(txt, "tests/input/input4.txt");
	p(txt, 1, "Huh");
	show(txt);
	
	std::string output = testing::internal::GetCapturedStdout();
	std::string target = GetText("tests/input/output4.txt");
	
	ASSERT_EQ(output, target);
}

TEST(p, DefaultFirstLine) {
	testing::internal::CaptureStdout();
	
	text txt = create_text();
	load(txt, "tests/input/input4.txt");
	p(txt, 0, "Huh");
	show(txt);
	
	std::string output = testing::internal::GetCapturedStdout();
	std::string target = GetText("tests/input/output7.txt");
	
	ASSERT_EQ(output, target);
}

TEST(p, DefaultLastLine) {
	testing::internal::CaptureStdout();
	
	text txt = create_text();
	load(txt, "tests/input/input4.txt");
	p(txt, 4, "Huh");
	show(txt);
	
	std::string output = testing::internal::GetCapturedStdout();
	std::string target = GetText("tests/input/output8.txt");
	
	ASSERT_EQ(output, target);
}

TEST(p, NullFile) {
	testing::internal::CaptureStderr();

	p(NULL, 0, "Huh");
	
	std::string capturedStderr = testing::internal::GetCapturedStderr();
	ASSERT_NE(capturedStderr, "");
}

TEST(p, EmptyFile) {
	testing::internal::CaptureStderr();
	
	text txt = create_text();
	load(txt, "tests/input/empty.txt");
	p(txt, 0, "Huh");
	
	std::string capturedStderr = testing::internal::GetCapturedStderr();
	ASSERT_NE(capturedStderr, "");
}

TEST(p, InvalidLineNumber) {
	testing::internal::CaptureStderr();
	
	text txt = create_text();
	load(txt, "tests/input/input4.txt");
	p(txt, 9999, "Huh");
	
	std::string capturedStderr = testing::internal::GetCapturedStderr();
	ASSERT_NE(capturedStderr, "");
}

TEST(p, NullContentsPointer) {
	testing::internal::CaptureStderr();
	
	text txt = create_text();
	load(txt, "tests/input/input4.txt");
	p(txt, 0, NULL);
	
	std::string capturedStderr = testing::internal::GetCapturedStderr();
	ASSERT_NE(capturedStderr, "");
}

TEST(save, Default) {
	text txt = create_text();
	load(txt, "tests/input/input6.txt");
	save(txt, "test.txt");
	
	std::string origin = GetText("tests/input/input6.txt");
	std::string target = GetText("test.txt");
	std::remove("test.txt");
	
	ASSERT_EQ(origin, target);
}

TEST(save, EmptyFile) {
	testing::internal::CaptureStderr();
	
	text txt = create_text();
	load(txt, "tests/input/empty.txt");
	save(txt, "test.txt");

	std::string capturedStderr = testing::internal::GetCapturedStderr();
	std::remove("test.txt");
	ASSERT_NE(capturedStderr, "");
}

TEST(save, NullFile) {
	testing::internal::CaptureStderr();
	
	save(NULL, "test.txt");
	
	std::string capturedStderr = testing::internal::GetCapturedStderr();
	std::remove("test.txt");
	ASSERT_NE(capturedStderr, "");
}


TEST(save, FileOpenError) {
	testing::internal::CaptureStderr();
	
	text txt = create_text();
	load(txt, "tests/input/input6.txt");
	save(txt, "/");
	
	std::string capturedStderr = testing::internal::GetCapturedStderr();
	ASSERT_NE(capturedStderr, "");
}

#endif