# Creating a personal repository with the correct .gitignore and simple README
## Creating a repo
To put your project up on Git, you'll need to create a repository for it to live in. Almost all git services support function of adding new repo like that:  
Creating a new repo:

![](https://docs.github.com/assets/images/help/repository/repo-create.png)

Choosing name of the repo:

![](https://docs.github.com/assets/images/help/repository/create-repository-name.png )

### README files
A README file is a text file  containing information for the user about the software program or utility. README files often contain instructions and additional help, and details about patches or updates.
This button will help you to create README file:

![](https://docs.github.com/assets/images/help/repository/initialize-with-readme.png)

## Adding gitignore file
Git sees every file in your working copy as one of three things:
- tracked - a file which has been previously staged or committed;
- untracked - a file which has not been staged or committed; or
- ignored - a file which Git has been explicitly told to ignore.

Ignored files are usually build artifacts and machine generated files that can be derived from your repository source or should otherwise not be committed.

# Creating develop and master branches
To create new branch we use command "git chechout -b <branchname>"
Main branch in repo often called "master" and the branch in which we will work is "develop"
Branches are pointers to the version of the program:

![](https://wac-cdn.atlassian.com/dam/jcr:389059a7-214c-46a3-bc52-7781b4730301/hero.svg?cdnVersion=1712)

# Setting the develop branch as the default
To choose branch we use command "git checkout <branchname>" if it already exists
To choose develop branch we type "git checkout develop" and start working. And we start working in it as in the main

![](misc/rus/images/scr1.png)

# Creating an issue for creating the current manual
Use issues to collaborate on ideas, solve problems, and plan work. Share and discuss proposals with your team and with outside collaborators.
You can use issues for many purposes, customized to your needs and workflow.

- Discuss the implementation of an idea.
- Track tasks and work status.
- Accept feature proposals, questions, support requests, or bug reports.
- Elaborate on code implementations.

To make an issue on gitlab you need to navigate to Projects Dashboard > Issues > New issue

![](misc/rus/images/new_issue_from_tracker_list.png)

# Creating a branch for the issue
To solve the problem we may create the new branch (to avoid damaging a working part of the programm) by using "git chechout -b <issue fix>"

![](misc/rus/images/scr2.png)

# Creating a merge request on the develop branch
If your development workflow requires an issue for every merge request, you can create a branch directly from the issue to speed the process up. The new branch, and later its merge request, are marked as related to this issue. Once merged, the merge request closes the issue. 

![](misc/rus/images/web_editor_new_branch.png)

# Commenting and accepting the request
With merge request approval rules, you can set the minimum number of required approvals before work can merge into your project. You can also extend these rules to define what types of users can approve work. Some examples of rules you can create include:

- Users with specific permissions can always approve work.
- Code owners can approve work for files they own.
- Users with specific permissions can approve work, even if they don’t have merge rights to the - - repository.
- Users with specific permissions can be allowed or denied the ability to override approval rules on a specific merge request.

# Creating a stable version in the master with a tag
Like most VCSs, Git has the ability to tag specific points in a repository’s history as being important. Typically, people use this functionality to mark release points (v1.0, v2.0 and so on).  

![](misc/rus/images/scr3.png)

# Working with wiki for the project
If you don’t want to keep your documentation in your repository, but you want to keep it in the same project as your code, you can use the wiki GitLab provides in each GitLab project. Every wiki is a separate Git repository, so you can create wiki pages in the web interface, or locally using Git.

To access the wiki for a project or group, go to the page for your project or group and, in the left sidebar, select Wiki. If Wiki is not listed in the left sidebar, a project administrator has disabled it.

GitLab wikis support Markdown, RDoc, AsciiDoc, and Org for content. Wiki pages written in Markdown support all Markdown features, and also provide some wiki-specific behavior for links.

