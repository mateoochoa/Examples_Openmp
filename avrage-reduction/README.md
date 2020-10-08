# avarage-reduction

En esta sección se mide el tiempo que tardan diferentes hilos en realizar una suma acumulada de 1 a 600 millones, para esto se implementa una sección paralela con la clausula for reduction, para que cada worker copie el valor del acumulador y cuando termine se lo sume al valor global.