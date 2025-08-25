/*
 * Copyright (c) 2024 Matteo Cadoni
 * This file is part of libtusclient, licensed under the MIT License.
 * See the LICENSE file in the project root for more information.
 */

#ifndef INCLUDE_CACHE_TUSFILE_H_
#define INCLUDE_CACHE_TUSFILE_H_

#include <string>
#include <filesystem>
#include <nlohmann/json.hpp>
#include <boost/uuid/uuid.hpp>

#include "ctus.h"

namespace TUS::Cache {
    /**
     * @brief The TUSFile class represents a file upload record in the cache.
     * When a file is uploaded, a record is created and stored in the cache, this
     * needs to be done in order to resume the upload if the upload is interrupted.
     * The record contains the file path, the upload URL, the upload offset,
     * the size of the full file and the application name that created the record.
     * This class provides methods for storing and retrieving data from the cache.
     */
    class EXPORT_LIBTUSCLIENT TUSFile {
    public:
        /**
         * @brief Construct a new TUSFile object.
         * @param filePath The path of the file to be uploaded.
         * @param uploadUrl The URL to which the file will be uploaded.
         * @param appName The name of the application that created the record.
         */
        TUSFile(const std::filesystem::path &filePath, const std::string &uploadUrl, const std::string &appName,
                boost::uuids::uuid uuid, std::string tusID = "");

        explicit TUSFile(const std::shared_ptr<TUSFile> &file);

        ~TUSFile();

        [[nodiscard]] std::filesystem::path getFilePath() const;

        [[nodiscard]] std::string getUploadUrl() const;

        [[nodiscard]] std::string getAppName() const;

        [[nodiscard]] std::string getIdentificationHash() const;

        [[nodiscard]] int64_t getFileSize() const;

        [[nodiscard]] int64_t getLastEdit() const;

        [[nodiscard]] int64_t getUploadOffset() const;

        [[nodiscard]] int getResumeFrom() const;

        [[nodiscard]] std::string getTusIdentifier() const;

        [[nodiscard]] boost::uuids::uuid getUuid() const;

        int getChunkNumber() const;

        void setLastEdit(int64_t lastEdit);

        void setUploadOffset(int64_t uploadOffset);

        void setTusIdentifier(std::string tusIdentifier);

        void setResumeFrom(int resumeFrom);

        void setChunkNumber(int chunkNumber);

        [[nodiscard]] bool select(const std::string &filePath, const std::string &appName, const std::string &uploadUrl) const;

    private:
        int64_t m_lastEdit; /* last time the record was edited in unix time */
        const std::filesystem::path m_filePath;
        const std::string m_uploadUrl;
        const std::string m_appName;
        int64_t m_uploadOffset; /* the offset of the file that has been uploaded */
        int m_resumeFrom{}; /* the offset from which the upload should resume */
        const int64_t m_fileSize;
        std::string m_tusIdentifier; /* the identifier of the file */
        const boost::uuids::uuid m_uuid; /* the uuid of the file */
        int m_chunkNumber{}; /* the number of the chunk that is being uploaded */

        const std::string m_identifcationHash; /* the hash of the file path and the upload url and app name*/

        void updateFile();
    };
} // namespace Model


#endif // INCLUDE_CACHE_TUSFILE_H_
