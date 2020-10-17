#!/usr/bin/perl

@Programs = ("algoritmo_1", "algoritmo_2", "algoritmo_3");
@Charges = (300, 600, 1000, 2000, 3000); #vectores
@Threads = (2,3,4);
$Rep = 12; #Repeticiones
$PATH = "/home/mateo/Programación_Paralelo/OPMP/MPP1";
foreach $aux1 (@Programs){
    foreach $aux2 (@Charges){
        foreach $aux3 (@Threads){
            $file = $aux1."_".$aux2."_".$aux3.".txt";
            printf("$file\n");
            for ( $i=0 ; $i<$Rep ; $i++ ){
                system("./$aux1 $aux2 $aux3 >> $PATH/TXT/$file");            
            }
            close($file);
        }
    }
}