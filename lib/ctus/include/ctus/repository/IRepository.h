/*
 * Copyright (c) 2024 Matteo Cadoni
 * This file is part of libtusclient, licensed under the MIT License.
 * See the LICENSE file in the project root for more information.
 */
#ifndef INCLUDE_REPOSITORY_IREPOSITORY_H_
#define INCLUDE_REPOSITORY_IREPOSITORY_H_

#include <vector>

#include "ctus.h"


namespace TUS::Repository {
    template<typename T>
    class EXPORT_CTUS IRepository {
    public:
        virtual ~IRepository() = default;

        virtual void add(std::shared_ptr<T>) = 0;

        virtual void remove(std::shared_ptr<T>) = 0;

        virtual std::shared_ptr<T> findByHash(const std::string &id) const = 0;

        virtual std::vector<std::shared_ptr<T> > findAll() const = 0;

        virtual bool open() = 0;

        virtual bool save() = 0;
    };
} // namespace TUS::Repository


#endif // INCLUDE_REPOSITORY_IREPOSITORY_H_
