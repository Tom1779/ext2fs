#ifndef TYPE_H
#define TYPE_H

#include <ext2fs/ext2_fs.h>

/*************** type.h file for LEVEL-1 ****************/
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct ext2_super_block SUPER;
typedef struct ext2_group_desc GD;
typedef struct ext2_inode INODE;
typedef struct ext2_dir_entry_2 DIR;

SUPER *sp;
GD *gp;
INODE *ip;
DIR *dp;

#define FREE 0
#define READY 1

#define BLKSIZE 1024
#define NMINODE 128
#define NPROC 2

#define EXT2_S_IFMT 0xF000  /* format mask  */
#define EXT2_S_IFLNK 0xA000 /* symbolic link */
#define EXT2_S_IFREG 0x8000 /* directory */

typedef struct minode
{
  INODE INODE;  // INODE structure on disk
  int dev, ino; // (dev, ino) of INODE
  int refCount; // in use count
  int dirty;    // 0 for clean, 1 for modified

  int mounted;          // for level-3
  struct mntable *mptr; // for level-3
} MINODE;

typedef struct proc
{
  struct proc *next;
  int pid; // process ID
  int ppid;
  int status;
  int uid; // user ID
  int gid;
  MINODE *cwd; // CWD directory pointer
} PROC;

#endif