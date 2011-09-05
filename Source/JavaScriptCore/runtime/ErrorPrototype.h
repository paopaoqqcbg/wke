/*
 *  Copyright (C) 1999-2000 Harri Porten (porten@kde.org)
 *  Copyright (C) 2008 Apple Inc. All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef ErrorPrototype_h
#define ErrorPrototype_h

#include "ErrorInstance.h"

namespace JSC {

    class ObjectPrototype;

    class ErrorPrototype : public ErrorInstance {
    public:
        typedef ErrorInstance Base;

        static ErrorPrototype* create(ExecState* exec, JSGlobalObject* globalObject, Structure* structure)
        {
            return new (allocateCell<ErrorPrototype>(*exec->heap())) ErrorPrototype(exec, globalObject, structure);
        }
        
        static const ClassInfo s_info;

        static Structure* createStructure(JSGlobalData& globalData, JSValue prototype)
        {
            return Structure::create(globalData, prototype, TypeInfo(ObjectType, StructureFlags), AnonymousSlotCount, &s_info);
        }

    protected:
        ErrorPrototype(ExecState*, JSGlobalObject*, Structure*);
        void constructorBody(ExecState*, JSGlobalObject*);

        static const unsigned StructureFlags = OverridesGetOwnPropertySlot | ErrorInstance::StructureFlags;
        static const unsigned AnonymousSlotCount = ErrorInstance::AnonymousSlotCount + 1;

    private:
        virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
        virtual bool getOwnPropertyDescriptor(ExecState*, const Identifier&, PropertyDescriptor&);
    };

} // namespace JSC

#endif // ErrorPrototype_h