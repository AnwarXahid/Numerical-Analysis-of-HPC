#!/bin/bash
#SBATCH --job-name=simpson
#SBATCH --output=simpson_output.txt
#SBATCH --partition=instruction
#SBATCH --qos=instruction
#SBATCH --account=s2025.coms.525.1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=8
#SBATCH --time=00:01:00

export OMP_NUM_THREADS=8
./simpson_parallel

