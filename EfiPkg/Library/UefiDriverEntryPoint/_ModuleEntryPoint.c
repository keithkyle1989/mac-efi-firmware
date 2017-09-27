/** @file
  Copyright (c) 2005 - 2017, Apple Inc.  All rights reserved.<BR>

  This program and the accompanying materials have not been licensed.
  Neither is its usage, its redistribution, in source or binary form,
  licensed, nor implicitely or explicitely permitted, except when
  required by applicable law.

  Unless required by applicable law or agreed to in writing, software
  distributed is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
  OR CONDITIONS OF ANY KIND, either express or implied.
**/

#include <Uefi.h>

EFI_STATUS
EFIAPI
EfiMain (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

/**
  The entry point of PE/COFF Image for a DXE Driver, DXE Runtime Driver, DXE SMM 
  Driver, or UEFI Driver. 

  This function is the entry point for a DXE Driver, DXE Runtime Driver, DXE SMM Driver,
  or UEFI Driver.  This function must call ProcessLibraryConstructorList() and
  ProcessModuleEntryPointList(). If the return status from ProcessModuleEntryPointList()
  is an error status, then ProcessLibraryDestructorList() must be called. The return 
  value from ProcessModuleEntryPointList() is returned. If _gDriverUnloadImageCount 
  is greater than zero, then an unload handler must be registered for this image 
  and the unload handler must invoke ProcessModuleUnloadList().
  If _gUefiDriverRevision is not zero and SystemTable->Hdr.Revision is less than 
  _gUefiDriverRevison, then return EFI_INCOMPATIBLE_VERSION.


  @param  ImageHandle  The image handle of the DXE Driver, DXE Runtime Driver, 
                       DXE SMM Driver, or UEFI Driver.
  @param  SystemTable  A pointer to the EFI System Table.

  @retval  EFI_SUCCESS               The DXE Driver, DXE Runtime Driver, DXE SMM 
                                     Driver, or UEFI Driver exited normally.
  @retval  EFI_INCOMPATIBLE_VERSION  _gUefiDriverRevision is greater than 
                                    SystemTable->Hdr.Revision.
  @retval  Other                     Return value from ProcessModuleEntryPointList().
**/
EFI_STATUS
EFIAPI
_ModuleEntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  return EfiMain (ImageHandle, SystemTable);
}
