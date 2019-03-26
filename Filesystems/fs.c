struct fs_t {
  // you determine what goes here
  int fileDesc;

};

struct inode {
  char name[16];        //file name
  int size;             // file size (in number of blocks)
  int blockPointers[8]; // direct block pointers
  int used;             // 0 => inode is free; 1 => in use
}

// open the file with the above name
void fs_open(struct fs_t* fs, char diskName[16]) {
   // this file will act as the "disk" for your file system
   fs->fileDesc = open(diskName, O_RDWR);
}

// close and clean up all associated things
void fs_close(struct fs_t* fs) {
   // this file will act as the "disk" for your file system
   close(fs->fileDesc);
}

//create a file with this name and this size
void fs_create(struct fs_t* fs, char name[16], int size) {

  // high level pseudo code for creating a new file

  // Step 1: check to see if we have sufficient free space on disk by
  // reading in the free block list. To do this:
  // move the file pointer to the start of the disk file.
  // Read the first 128 bytes (the free/in-use block information)
  // Scan the list to make sure you have sufficient free blocks to
  // allocate a new file of this size

  // Step 2: we look  for a free inode on disk
  // Read in a inode
  // check the "used" field to see if it is free
  // If not, repeat the above two steps until you find a free inode
  // Set the "used" field to 1
  // Copy the filename to the "name" field
  // Copy the file size (in units of blocks) to the "size" field

  // Step 3: Allocate data blocks to the file
  // for(i=0;i<size;i++)
  // Scan the block list that you read in Step 1 for a free block
  // Once you find a free block, mark it as in-use (Set it to 1)
  // Set the blockPointer[i] field in the inode to this block number.
  // end for

  // Step 4: Write out the inode and free block list to disk
  // Move the file pointer to the start of the file
  // Write out the 128 byte free block list
  // Move the file pointer to the position on disk where this inode was stored
  // Write out the inode
	char freeList[128];
	int freeBlocks = 0;
	
	if(size > 8){
		return;
	}

	lseek(name, 0, SEEK_SET);		//Free List is first 128 bytes of disk
	read(fs->fileDesc, freeList, 128);
	for(int i = 0; i <= 128; ++i){
		if(!freeList[i]){
			++freeBlocks;
		}
	}
	if(size >= freeBlocks){
		return;
	}
	//END STEP 1
	inode currInode;
	for(int i = 0; i <= 128; ++ i){
		read(fs->fileDesc, &currInode, size_of(inode));
		if(!currInode->used){
			currInode->used = 1;
			currInode->name = name;
			currInode->size = size;
			break;
		}	
	}
	//END STEP 2
	int inodeIndex;
	for(int i=0; i<size; i++){
		
	}
	

}

// Delete the file with this name
void fs_delete(struct fs_t* fs, char name[16]) {

  // Step 1: Locate the inode for this file
  // Move the file pointer to the 1st inode (129th byte)
  // Read in a inode
  // If the iinode is free, repeat above step.
  // If the iinode is in use, check if the "name" field in the
  // inode matches the file we want to delete. IF not, read the next
  //  inode and repeat

  // Step 2: free blocks of the file being deleted
  // Read in the 128 byte free block list (move file pointer to start
  //   of the disk and read in 128 bytes)
  // Free each block listed in the blockPointer fields as follows:
  // for(i=0;i< inode.size; i++)
     // freeblockList[ inode.blockPointer[i] ] = 0;

  // Step 3: mark inode as free
  // Set the "used" field to 0.

  // Step 4: Write out the inode and free block list to disk
  // Move the file pointer to the start of the file
  // Write out the 128 byte free block list
  // Move the file pointer to the position on disk where this inode was stored
  // Write out the inode

}

// List names of all files on disk
void fs_ls(struct fs_t* fs) {
  // Step 1: read in each inode and print!
  // Move file pointer to the position of the 1st inode (129th byte)
  // for(i=0;i<16;i++)
    // Read in a inode
    // If the inode is in-use
      // print the "name" and "size" fields from the inode
  // end for
}

// read this block from this file
void fs_read(struct fs_t* fs, char name[16], int blockNum, char buf[1024]) {
   // Step 1: locate the inode for this file
   // Move file pointer to the position of the 1st inode (129th byte)
   // Read in a inode
   // If the inode is in use, compare the "name" field with the above file
   // IF the file names don't match, repeat

   // Step 2: Read in the specified block
   // Check that blockNum < inode.size, else flag an error
   // Get the disk address of the specified block
   // That is, addr = inode.blockPointer[blockNum]
   // move the file pointer to the block location (i.e., to byte # addr*1024 in the file)

   // Read in the block! => Read in 1024 bytes from this location into the buffer "buf"

}

// write this block to this file
void fs_write(struct fs_t* fs, char name[16], int blockNum, char buf[1024]) {

   // Step 1: locate the inode for this file
   // Move file pointer to the position of the 1st inode (129th byte)
   // Read in a inode
   // If the inode is in use, compare the "name" field with the above file
   // If the file names don't match, repeat

   // Step 2: Write to the specified block
   // Check that blockNum < inode.size, else flag an error
   // Get the disk address of the specified block
   // That is, addr = inode.blockPointer[blockNum]
   // move the file pointer to the block location (i.e., byte # addr*1024)

   // Write the block! => Write 1024 bytes from the buffer "buff" to this location

}

// REPL entry point
void fs_repl() {
/*
 * diskName            // name of the file that emulates the disk
 * C fileName Size     // create a file of this size
 * D fileNAme          // delete this file
 * L                   // list all files on disk and their sizes
 * R fileName blockNum // read this block from this file
 * W fileName blockNum // write to this block in the file (use a dummy 1KB buffer)
 */
}

// Extra credit
void fs_defragment (struct fs_t* fs) {

}
