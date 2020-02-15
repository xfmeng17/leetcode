# -*- coding:utf-8 -*-

# 1. Change this url to get json data:
# https://leetcode.com/contest/api/ranking/weekly-contest-175/?pagination=1&region=global
# 2. Download page and rename to weekly-contest-xxx.json
# 3. Put this json file to `tools/contest_json`
# 4. Check real problem id in LeetCode **Problems** tag, like 1346
# 5. Go `tools/` Run:
# py contest_template.py contest_json/weekly-contest-xxx.json 1346
# If problem id can match, then input 0. (What's wrong with LeetCode??)
#
## '4. Go `tools/` Run:
## py contest_template.py contest_json/weekly-contest-xxx.json

import os
import sys
import json
from datetime import datetime

def genHead1(contest, data, pid_arr):
    md_text = ""
    md_text += "# [" + contest + "](https://leetcode.com/contest/"
    md_text += contest + "/)" + "\n\n"
    return md_text

def genHead2(contest, data, pid_arr):
    md_text = ""
    date = ""
    for submission in data["submissions"]:
        for key in submission:
            ts = int(submission[key]["date"])
            date = datetime.utcfromtimestamp(ts).strftime('%Y-%m-%d')
            break
        break
    md_text += "## " + date + " "
    for pid in pid_arr:
        md_text += "`" + str(pid) + "` "
    md_text += "\n\n"
    return md_text

def genHead3(contest, data, pid_arr):
    md_text = ""
    for i in range(0, 4):
        pid = pid_arr[i]
        title = data["questions"][i]["title"]
        title_slug = data["questions"][i]["title_slug"]
        md_str = ""
        md_str += "### [" + str(pid) + ". "
        md_str += title + "](https://leetcode.com/problems/"
        md_str += title_slug + "/)"
        md_str += "\n\n"
        md_str += "- [cpp](https://github.com/xfmeng17/leetcode/blob/master/cpp/"
        md_str += str(pid) + '.cpp)'
        md_str += "\n\n\n"
        md_text += md_str
    return md_text

def getRealPid(data, real_start_pid):
    pid_arr = []
    if real_start_pid == 0:
        for question in data["questions"]:
            real_start_pid = question["question_id"]
            break
    for question in data["questions"]:
        pid_arr.append(real_start_pid)
        real_start_pid += 1
    return pid_arr

def genMdFile(filepath, real_start_pid):
    name_lo = filepath.find('/') + 1
    name_hi = filepath.find('.') - 1
    contest = filepath[name_lo:name_hi+1]
    
    md_text = ""
    with open(filepath) as json_file:
        data = json.load(json_file)
        pid_arr = getRealPid(data, real_start_pid)
        md_text += genHead1(contest, data, pid_arr)
        md_text += genHead2(contest, data, pid_arr)
        md_text += genHead3(contest, data, pid_arr)
        # print(md_text)

    arr = contest.split('-')
    print("filepath:", filepath)
    print("contest:", contest)
    print("arr:", arr)
    md_dir = "../docs/notes/" + arr[0] + '_' + arr[1] + '/'
    md_file = arr[2].zfill(4) + ".md"
    with open(md_dir+md_file, 'w') as md_file:
        md_file.write(md_text)

if __name__=='__main__':
    if len(sys.argv) < 2:
        print("Usage: python contest_template.py xxxx.json real_start_id")
        exit
    genMdFile(sys.argv[1], int(sys.argv[2]))
