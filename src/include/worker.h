/*
 * Copyright (C) 2020 Red Hat
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this list
 * of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright notice, this
 * list of conditions and the following disclaimer in the documentation and/or other
 * materials provided with the distribution.
 * 
 * 3. Neither the name of the copyright holder nor the names of its contributors may
 * be used to endorse or promote products derived from this software without specific
 * prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef PGAGROAL_WORKER_H
#define PGAGROAL_WORKER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ev.h>
#include <stdlib.h>

#define WORKER_SUCCESS        0
#define WORKER_FAILURE        1
#define WORKER_SHUTDOWN       2
#define WORKER_CLIENT_FAILURE 3
#define WORKER_SERVER_FAILURE 4
#define WORKER_SERVER_FATAL   5

/** @struct
 * The worker structure for each IO event
 */
struct worker_io
{
   struct ev_io io;      /**< The libev base type */
   int client_fd;        /**< The client descriptor */
   int server_fd;        /**< The server descriptor */
   int slot;             /**< The slot */
   void* shmem;          /**< The shared memory segment */
   void* pipeline_shmem; /**< The shared memory segment for the pipeline */
};

extern volatile int running;
extern volatile int exit_code;

/**
 * Create a worker instance
 * @param fd The client descriptor
 * @param address The client address
 * @param shmem The shared memory segment
 * @param pipeline_shmem The shared memory segment for the pipeline
 */
void
pgagroal_worker(int fd, char* address, void* shmem, void* pipeline_shmem);

#ifdef __cplusplus
}
#endif

#endif
