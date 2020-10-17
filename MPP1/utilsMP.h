/***************************************************************************************************/
/*           Archivo: utilsMP.h                                                                    */
/*             Autor: Miguel Angel and Luis Mateo                                                  */
/*             Email: miguelan.ruiz@correo.usa.edu.co; luis.ochoa3@correo.usa.edu.co               */
/*         Ubicacion: Bogota / Colombia                                                            */
/*                                                                                                 */
/*                                                                                                 */
/*      Descripcion:                                                                               */
/* Esta biblioteca se encarga de gestionar los parametros de flujo dentro de una region o se-        */
/* ccion paralela como son la inicializacion, identificacion y tomas de rendimiento. Incluso       */
/* permite la presentacion en consola de estas medidas.                                            */
/*                                                                                                 */
/***************************************************************************************************/
void mpStart(int threadID);
void mpStop(int threadID);
void argsInit(int argc, char* argv[]);
int mpParallel(void);
void mpEnd(void);
