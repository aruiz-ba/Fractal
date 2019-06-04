/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setgpu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 16:57:27 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/06/04 17:16:32 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <OpenCL/opencl.h>

/*void setgpu()
{
	char *source;
	int queue;
	
	source = {
		"kernel void calcSin(global float *data) {\n"
		"	int id = get_global_id(0);\n"
		"	data[id] = sin(data[id]);\n"
		"}\n"
	}
	//Set up OpenCL
	clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU  , 1, &device, NULL)
	context = clCreateContext(NULL, 1, &device, NULL, NULL, NULL);
	queue = clCreateCommandQueue(context, device, (cl_command_queue_prperties)0, NULL);

	//COMPILE KERNEL
	program = clCreateProgramWithSource(context, 1, (const char**)&source, NULL, NULL);
	clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
	kernel = clCreateKernel(program, "calcSin", NULL);

	//Create the memory object
	buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, DATA_SIZE, NULL, NULL);

	//copy data to input
	clEnqueueWriteBuffer(queue, buffer, CL_FALSE, 0, DATA_SIZE, data, 0, NULL, NULL);

	//Execute the kernel
	clSetKernelArg(kernel, 0, sizeof(buffer), &buffer);
	size_t global_dimensions[] = {LENGTH,0,0};
	clEnqueueNDRangeKernel(queue, kernel, 1, NULL, global_dimensions, NULL, 0, NULL, NULL);

	//Read back the results
	clEnqueueReadBuffer(queue, buffer, CL_FALSE, 0, sizeof(cl_float)*LENGTH, DATAM 0, NULL, NULL);

	//Wait for everything to finish
	clFinish(queue);
}*/
