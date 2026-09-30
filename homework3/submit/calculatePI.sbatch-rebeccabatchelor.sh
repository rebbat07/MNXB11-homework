#!/bin/sh

#SBATCH -J "MNXB11 Pi homework"
#SBATCH --time=00:15:00
#SBATCH -A hep2023-1-6
#SBATCH --mem 30G



# Launch the calculatePI.sh application script using the container script
run_in_container_calculatePI.sh
